/*
 *
 *    Copyright (c) 2020-2021 Project CHIP Authors
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
 *  @file
 *    This file contains definitions for Device class. The objects of this
 *    class will be used by Controller applications to interact with CHIP
 *    devices. The class provides mechanism to construct, send and receive
 *    messages to and from the corresponding CHIP devices.
 */

#pragma once

#include <app/DeviceProxy.h>
#include <app/util/attribute-filter.h>
#include <app/util/basic-types.h>
#include <messaging/ExchangeContext.h>
#include <messaging/ExchangeDelegate.h>
#include <messaging/ExchangeMgr.h>
#include <messaging/Flags.h>
#include <protocols/secure_channel/CASESession.h>
#include <protocols/secure_channel/SessionIDAllocator.h>
#include <transport/SessionManager.h>
#include <transport/TransportMgr.h>
#include <transport/raw/MessageHeader.h>
#include <transport/raw/UDP.h>

namespace chip {

class DeviceStatusDelegate;

struct DeviceProxyInitParams
{
    SessionManager * sessionManager          = nullptr;
    Messaging::ExchangeManager * exchangeMgr = nullptr;
    SessionIDAllocator * idAllocator         = nullptr;
    FabricInfo * fabricInfo                  = nullptr;

    Controller::DeviceControllerInteractionModelDelegate * imDelegate = nullptr;
};

class OperationalDeviceProxy;

typedef void (*OnDeviceConnected)(void * context, DeviceProxy * device);
typedef void (*OnDeviceConnectionFailure)(void * context, NodeId deviceId, CHIP_ERROR error);

class DLL_EXPORT OperationalDeviceProxy : public DeviceProxy, Messaging::ExchangeDelegate, public SessionEstablishmentDelegate
{
public:
    virtual ~OperationalDeviceProxy();
    OperationalDeviceProxy(DeviceProxyInitParams params, PeerId peerId)
    {
        VerifyOrReturn(params.sessionManager != nullptr);
        VerifyOrReturn(params.exchangeMgr != nullptr);
        VerifyOrReturn(params.idAllocator != nullptr);
        VerifyOrReturn(params.fabricInfo != nullptr);

        mInitParams = params;
        mPeerId     = peerId;
        mState      = State::NeedsAddress;
    }

    void Clear();

    /*
     * This function can be called to establish a secure session with the device.
     *
     * The device is expected to have been commissioned, A CASE session
     * setup will be triggered.
     *
     * On establishing the session, the callback function `onConnection` will be called. If the
     * session setup fails, `onFailure` will be called.
     *
     * If the session already exists, `onConnection` will be called immediately.
     */
    CHIP_ERROR Connect(Callback::Callback<OnDeviceConnected> * onConnection,
                       Callback::Callback<OnDeviceConnectionFailure> * onFailure);

    bool IsConnected() const { return mState == State::SecureConnected; }

    bool IsConnecting() const { return mState == State::Connecting; }

    /**
     *   Called when a connection is closing.
     *   The object releases all resources associated with the connection.
     */
    void OnConnectionExpired(SessionHandle session) override;

    /**
     *  Mark any open session with the device as expired.
     */
    CHIP_ERROR Disconnect() override;

    NodeId GetDeviceId() const override { return mPeerId.GetNodeId(); }
    /*
        // ----- Messaging -----
        CHIP_ERROR SendReadAttributeRequest(app::AttributePathParams aPath, Callback::Cancelable * onSuccessCallback,
                                            Callback::Cancelable * onFailureCallback, app::TLVDataFilter aTlvDataFilter) override;

        CHIP_ERROR SendSubscribeAttributeRequest(app::AttributePathParams aPath, uint16_t mMinIntervalFloorSeconds,
                                                 uint16_t mMaxIntervalCeilingSeconds, Callback::Cancelable * onSuccessCallback,
                                                 Callback::Cancelable * onFailureCallback) override;

        CHIP_ERROR SendWriteAttributeRequest(app::WriteClientHandle aHandle, Callback::Cancelable * onSuccessCallback,
                                             Callback::Cancelable * onFailureCallback) override;

        CHIP_ERROR SendCommands(app::CommandSender * commandObj) override;

        void AddReportHandler(EndpointId endpoint, ClusterId cluster, AttributeId attribute, Callback::Cancelable *
       onReportCallback, app::TLVDataFilter tlvDataFilter) override;

        void AddIMResponseHandler(void * commandObj, Callback::Cancelable * onSuccessCallback, Callback::Cancelable *
       onFailureCallback, app::TLVDataFilter tlvDataFilter = nullptr) override; void CancelIMResponseHandler(void * commandObj)
       override;
    */
    /**
     * @brief
     *   This function is called when a message is received from the corresponding
     *   device. The message ownership is transferred to the function, and it is expected
     *   to release the message buffer before returning.
     */
    CHIP_ERROR OnMessageReceived(Messaging::ExchangeContext * exchange, const PayloadHeader & payloadHeader,
                                 System::PacketBufferHandle && msgBuf) override;

    void OnResponseTimeout(Messaging::ExchangeContext * ec) override {}

    /**
     *   Update data of the device.
     *   This function will set new IP address, port and MRP retransmission intervals of the device.
     *   Since the device settings might have been moved from RAM to the persistent storage, the function
     *   will load the device settings first, before making the changes.
     */
    CHIP_ERROR UpdateDeviceData(const Transport::PeerAddress & addr, uint32_t mrpIdleInterval, uint32_t mrpActiveInterval);

    /**
     *   Set the delegate object which will be called when a message is received.
     *   The user of this Device object must reset the delegate (by calling
     *   SetDelegate(nullptr)) before releasing their delegate object.
     */
    void SetDelegate(DeviceStatusDelegate * delegate) { mStatusDelegate = delegate; }

    PeerId GetPeerId() const { return mPeerId; }

    bool MatchesSession(SessionHandle session) const { return mSecureSession.HasValue() && mSecureSession.Value() == session; }

    uint8_t GetNextSequenceNumber() override { return mSequenceNumber++; };

    CHIP_ERROR ShutdownSubscriptions() override;

    //////////// SessionEstablishmentDelegate Implementation ///////////////
    void OnSessionEstablishmentError(CHIP_ERROR error) override;
    void OnSessionEstablished() override;

    CASESession & GetCASESession() { return mCASESession; }

    Controller::DeviceControllerInteractionModelDelegate * GetInteractionModelDelegate() override { return mInitParams.imDelegate; }

    Messaging::ExchangeManager * GetExchangeManager() const override { return mInitParams.exchangeMgr; }

    chip::Optional<SessionHandle> GetSecureSession() const override { return mSecureSession; }

    bool GetAddress(Inet::IPAddress & addr, uint16_t & port) const override;

private:
    enum class State
    {
        Uninitialized,
        NeedsAddress,
        Initialized,
        Connecting,
        SecureConnected,
    };

    DeviceProxyInitParams mInitParams;

    CASESession mCASESession;

    PeerId mPeerId;

    Transport::PeerAddress mDeviceAddress = Transport::PeerAddress::UDP(Inet::IPAddress::Any);

    State mState = State::Uninitialized;

    DeviceStatusDelegate * mStatusDelegate = nullptr;
    Optional<SessionHandle> mSecureSession = Optional<SessionHandle>::Missing();

    uint8_t mSequenceNumber = 0;

    Callback::CallbackDeque mConnectionSuccess;
    Callback::CallbackDeque mConnectionFailure;

    CHIP_ERROR EstablishConnection();

    bool IsSecureConnected() const override { return mState == State::SecureConnected; }

    void EnqueueConnectionCallbacks(Callback::Callback<OnDeviceConnected> * onConnection,
                                    Callback::Callback<OnDeviceConnectionFailure> * onFailure);

    void DequeueConnectionSuccessCallbacks(bool executeCallback);
    void DequeueConnectionFailureCallbacks(CHIP_ERROR error, bool executeCallback);
};

} // namespace chip
