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
 *          Example project configuration file for CHIP.
 *
 *          This is a place to put application or project-specific overrides
 *          to the default configuration values for general CHIP features.
 *
 */

#pragma once

// Use a default pairing code if one hasn't been provisioned in flash.
#define CHIP_DEVICE_CONFIG_USE_TEST_SETUP_PIN_CODE 20202021
#define CHIP_DEVICE_CONFIG_USE_TEST_SETUP_DISCRIMINATOR 0xF00

// For convenience, Chip Security Test Mode can be enabled and the
// requirement for authentication in various protocols can be disabled.
//
//    WARNING: These options make it possible to circumvent basic Chip security functionality,
//    including message encryption. Because of this they MUST NEVER BE ENABLED IN PRODUCTION BUILDS.
//
#define CHIP_CONFIG_SECURITY_TEST_MODE 0
#define CHIP_CONFIG_REQUIRE_AUTH 1

/**
 * CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID
 *
 * 0x235A: Chip's Vendor Id.
 */
#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID 0x235A

/**
 * CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID
 *
 * 0x5350: EFR32 pigweed-app
 */
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID 0x5350

/**
 * CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_REVISION
 *
 * The product revision number assigned to device or product by the device vendor.  This
 * number is scoped to the device product id, and typically corresponds to a revision of the
 * physical device, a change to its packaging, and/or a change to its marketing presentation.
 * This value is generally *not* incremented for device software revisions.
 */
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_REVISION 1

/**
 * CHIP_DEVICE_CONFIG_DEVICE_FIRMWARE_REVISION_STRING
 *
 * A string identifying the firmware revision running on the device.
 * CHIP service currently expects the firmware version to be in the format
 * {MAJOR_VERSION}.0d{MINOR_VERSION}
 */
#ifndef CHIP_DEVICE_CONFIG_DEVICE_FIRMWARE_REVISION_STRING
#define CHIP_DEVICE_CONFIG_DEVICE_FIRMWARE_REVISION_STRING "0.1ALPHA"
#endif
/**
 * CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE
 *
 * Enable support for Chip-over-BLE (CHIPoBLE).
 */
#define CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE 1

/**
 * CHIP_DEVICE_CONFIG_ENABLE_CHIP_TIME_SERVICE_TIME_SYNC
 *
 * Enables synchronizing the device's real time clock with a remote Chip Time service
 * using the Chip Time Sync protocol.
 */
#define CHIP_DEVICE_CONFIG_ENABLE_CHIP_TIME_SERVICE_TIME_SYNC 0

/**
 * CHIP_DEVICE_CONFIG_USE_TEST_SERIAL_NUMBER
 *
 * Enables the use of a hard-coded default serial number if none
 * is found in Chip NV storage.
 */
#define CHIP_DEVICE_CONFIG_USE_TEST_SERIAL_NUMBER "DUMMY_SN"

/**
 * CHIP_CONFIG_EVENT_LOGGING_UTC_TIMESTAMPS
 *
 * Enable recording UTC timestamps.
 */
#define CHIP_CONFIG_EVENT_LOGGING_UTC_TIMESTAMPS 1

/**
 * CHIP_DEVICE_CONFIG_EVENT_LOGGING_DEBUG_BUFFER_SIZE
 *
 * A size, in bytes, of the individual debug event logging buffer.
 */
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_DEBUG_BUFFER_SIZE (512)

/**
 * CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL
 *
 * The interval (in units of 0.625ms) at which the device will send BLE advertisements while
 * in fast advertising mode.
 *
 * 40 (25ms).
 */
#define CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL 40

/**
 * CHIP_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL
 *
 * The interval (in units of 0.625ms) at which the device will send BLE advertisements while
 * in slow advertisement mode.
 *
 * 800 (500ms).
 */
#define CHIP_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL 800

/**
 * CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_TIMEOUT
 *
 * The amount of time in miliseconds after which BLE should change his advertisements
 * from fast interval to slow interval.
 *
 * 30000 (30 secondes).
 */
#define CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_TIMEOUT (30 * 1000)

/**
 * CHIP_DEVICE_CONFIG_BLE_ADVERTISING_TIMEOUT
 *
 * The amount of time in miliseconds after which BLE advertisement should be disabled, counting
 * from the moment of slow advertisement commencement.
 *
 * Defaults to 9000000 (15 minutes).
 */
#define CHIP_DEVICE_CONFIG_BLE_ADVERTISING_TIMEOUT (15 * 60 * 1000)
