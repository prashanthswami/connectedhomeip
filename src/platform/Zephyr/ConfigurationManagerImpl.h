/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
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
 *          Provides an implementation of the ConfigurationManager object
 *          for Zephyr platforms.
 */

#pragma once

#include <platform/internal/GenericConfigurationManagerImpl.h>

#include <platform/Zephyr/ZephyrConfig.h>

namespace chip {
namespace DeviceLayer {

/**
 * Concrete implementation of the ConfigurationManager singleton object for the Zephyr platform.
 */
class ConfigurationManagerImpl final : public Internal::GenericConfigurationManagerImpl<ConfigurationManagerImpl>,
                                       private Internal::ZephyrConfig
{
    // Allow the GenericConfigurationManagerImpl base class to access helper methods and types
    // defined on this class.
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    friend class Internal::GenericConfigurationManagerImpl<ConfigurationManagerImpl>;
#endif

private:
    // ===== Members that implement the ConfigurationManager public interface.

    CHIP_ERROR Init(void) override;
    CHIP_ERROR GetPrimaryWiFiMACAddress(uint8_t * buf) override;
    bool CanFactoryReset(void) override;
    void InitiateFactoryReset(void) override;
    CHIP_ERROR ReadPersistedStorageValue(::chip::Platform::PersistedStorage::Key key, uint32_t & value) override;
    CHIP_ERROR WritePersistedStorageValue(::chip::Platform::PersistedStorage::Key key, uint32_t value) override;

    // NOTE: Other public interface methods are implemented by GenericConfigurationManagerImpl<>.

    // ===== Members for internal use by the following friends.

    friend ConfigurationManager & ConfigurationMgr(void);
    friend ConfigurationManagerImpl & ConfigurationMgrImpl(void);

    static ConfigurationManagerImpl sInstance;

    // ===== Private members reserved for use by this class only.

    static void DoFactoryReset(intptr_t arg);
};

/**
 * Returns the public interface of the ConfigurationManager singleton object.
 *
 * chip applications should use this to access features of the ConfigurationManager object
 * that are common to all platforms.
 */
inline ConfigurationManager & ConfigurationMgr(void)
{
    return ConfigurationManagerImpl::sInstance;
}

/**
 * Returns the platform-specific implementation of the ConfigurationManager singleton object.
 *
 * chip applications can use this to gain access to features of the ConfigurationManager
 * that are specific to the nRF Connect SDK platform.
 */
inline ConfigurationManagerImpl & ConfigurationMgrImpl(void)
{
    return ConfigurationManagerImpl::sInstance;
}

inline bool ConfigurationManagerImpl::CanFactoryReset()
{
    return true;
}

inline CHIP_ERROR ConfigurationManagerImpl::ReadPersistedStorageValue(::chip::Platform::PersistedStorage::Key key, uint32_t & value)
{
    return ReadConfigValueCounter(key, value);
}

inline CHIP_ERROR ConfigurationManagerImpl::WritePersistedStorageValue(::chip::Platform::PersistedStorage::Key key, uint32_t value)
{
    return WriteConfigValueCounter(key, value);
}

inline CHIP_ERROR ConfigurationManagerImpl::GetPrimaryWiFiMACAddress(uint8_t * /* buf */)
{
    return CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE;
}

} // namespace DeviceLayer
} // namespace chip
