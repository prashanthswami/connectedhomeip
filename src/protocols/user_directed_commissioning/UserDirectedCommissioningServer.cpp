/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file implements an object for a Matter User Directed Commissioning unsolicitied
 *      recipient (server).
 *
 */

#include "UserDirectedCommissioning.h"

namespace chip {
namespace Protocols {
namespace UserDirectedCommissioning {

void UserDirectedCommissioningServer::OnMessageReceived(const Transport::PeerAddress & source, System::PacketBufferHandle && msg)
{
    ChipLogProgress(AppServer, "UserDirectedCommissioningServer::OnMessageReceived");

    PacketHeader packetHeader;

    ReturnOnFailure(packetHeader.DecodeAndConsume(msg));

    if (packetHeader.GetFlags().Has(Header::FlagValues::kEncryptedMessage))
    {
        ChipLogError(AppServer, "UDC encryption flag set - ignoring");
        return;
    }

    PayloadHeader payloadHeader;
    ReturnOnFailure(payloadHeader.DecodeAndConsume(msg));

    char instanceName[chip::Mdns::kMaxInstanceNameSize + 1];
    size_t instanceNameLength =
        (msg->DataLength() > (chip::Mdns::kMaxInstanceNameSize)) ? chip::Mdns::kMaxInstanceNameSize : msg->DataLength();
    msg->Read(Uint8::from_char(instanceName), instanceNameLength);

    instanceName[instanceNameLength] = '\0';

    ChipLogProgress(AppServer, "UDC instance=%s", instanceName);

    UDCClientState * client = mUdcClients.FindUDCClientState(instanceName);
    if (client == nullptr)
    {
        ChipLogProgress(AppServer, "UDC new instance state received");

        CHIP_ERROR err;
        err = mUdcClients.CreateNewUDCClientState(instanceName, &client);
        if (err != CHIP_NO_ERROR)
        {
            ChipLogError(AppServer, "UDC error creating new connection state");
            return;
        }

        // Call the registered InstanceNameResolver, if any.
        if (mInstanceNameResolver != nullptr)
        {
            mInstanceNameResolver->FindCommissionableNode(instanceName);
        }
        else
        {
            ChipLogError(AppServer, "UserDirectedCommissioningServer::OnMessageReceived no mInstanceNameResolver registered");
        }
    }

    mUdcClients.MarkUDCClientActive(client);
}

void UserDirectedCommissioningServer::SetUDCClientProcessingState(char * instanceName, UDCClientProcessingState state)
{
    UDCClientState * client = mUdcClients.FindUDCClientState(instanceName);
    if (client == nullptr)
    {
        // printf("SetUDCClientProcessingState new instance state received\n");
        CHIP_ERROR err;
        err = mUdcClients.CreateNewUDCClientState(instanceName, &client);
        if (err != CHIP_NO_ERROR)
        {
            ChipLogError(AppServer,
                         "UserDirectedCommissioningServer::SetUDCClientProcessingState error creating new connection state");
            return;
        }
    }

    ChipLogDetail(AppServer, "SetUDCClientProcessingState instance=%s new state=%d", instanceName, (int) state);

    client->SetUDCClientProcessingState(state);

    mUdcClients.MarkUDCClientActive(client);

    return;
}

void UserDirectedCommissioningServer::OnCommissionableNodeFound(const Mdns::DiscoveredNodeData & nodeData)
{
    if (nodeData.numIPs == 0)
    {
        ChipLogError(AppServer, "SetUDCClientProcessingState no IP addresses returned for instance name=%s", nodeData.instanceName);
        return;
    }
    if (nodeData.port == 0)
    {
        ChipLogError(AppServer, "SetUDCClientProcessingState no port returned for instance name=%s", nodeData.instanceName);
        return;
    }

    UDCClientState * client = mUdcClients.FindUDCClientState(nodeData.instanceName);
    if (client != nullptr && client->GetUDCClientProcessingState() == UDCClientProcessingState::kDiscoveringNode)
    {
        ChipLogDetail(AppServer, "OnCommissionableNodeFound instance: name=%s old_state=%d new_state=%d", client->GetInstanceName(),
                      (int) client->GetUDCClientProcessingState(), (int) UDCClientProcessingState::kPromptingUser);
        client->SetUDCClientProcessingState(UDCClientProcessingState::kPromptingUser);

        // currently IPv6 addresses do not work for some reason
        bool foundV4 = false;
        for (int i = 0; i < nodeData.numIPs; ++i)
        {
            if (nodeData.ipAddress[i].IsIPv4())
            {
                foundV4 = true;
                client->SetPeerAddress(chip::Transport::PeerAddress::UDP(nodeData.ipAddress[i], nodeData.port));
                break;
            }
        }
        // use IPv6 as last resort
        if (!foundV4)
        {
            client->SetPeerAddress(chip::Transport::PeerAddress::UDP(nodeData.ipAddress[0], nodeData.port));
        }

        // client->SetPeerAddress(chip::Transport::PeerAddress::UDP(nodeData.ipAddress[0], nodeData.port));
        client->SetDeviceName(nodeData.deviceName);
        client->SetLongDiscriminator(nodeData.longDiscriminator);

        // Call the registered mUserConfirmationProvider, if any.
        if (mUserConfirmationProvider != nullptr)
        {
            mUserConfirmationProvider->OnUserDirectedCommissioningRequest(*client);
        }
    }
}

void UserDirectedCommissioningServer::PrintUDCClients()
{
    for (size_t i = 0; i < kMaxUDCClients; i++)
    {
        UDCClientState * state = GetUDCClients().GetUDCClientState(i);
        if (state == nullptr)
        {
            ChipLogProgress(AppServer, "UDC Client[%ld] null", i);
        }
        else
        {
            char addrBuffer[chip::Transport::PeerAddress::kMaxToStringSize];
            state->GetPeerAddress().ToString(addrBuffer);

            ChipLogProgress(AppServer, "UDC Client[%ld] instance=%s deviceName=%s address=%s, disc=%d", i, state->GetInstanceName(),
                            state->GetDeviceName(), addrBuffer, state->GetLongDiscriminator());
        }
    }
}

} // namespace UserDirectedCommissioning
} // namespace Protocols
} // namespace chip
