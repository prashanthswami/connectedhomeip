/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

// Prevent multiple inclusion
#pragma once

// Default values for the attributes longer than a pointer,
// in a form of a binary blob
// Separate block is generated for big-endian and little-endian cases.
#if BIGENDIAN_CPU
#define GENERATED_DEFAULTS                                                                                                         \
    {                                                                                                                              \
                                                                                                                                   \
        /* Endpoint: 0, Cluster: OTA Software Update Requestor (server), big-endian */                                             \
                                                                                                                                   \
        /* 0 - default ota provider, */                                                                                            \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                      \
                                                                                                                                   \
            /* Endpoint: 0, Cluster: General Commissioning (server), big-endian */                                                 \
                                                                                                                                   \
            /* 17 - Breadcrumb, */                                                                                                 \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                                                                        \
                                                                                                                                   \
            /* 25 - BasicCommissioningInfoList, */                                                                                 \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                                                                              \
    }

#else // !BIGENDIAN_CPU
#define GENERATED_DEFAULTS                                                                                                         \
    {                                                                                                                              \
                                                                                                                                   \
        /* Endpoint: 0, Cluster: OTA Software Update Requestor (server), little-endian */                                          \
                                                                                                                                   \
        /* 0 - default ota provider, */                                                                                            \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                      \
                                                                                                                                   \
            /* Endpoint: 0, Cluster: General Commissioning (server), little-endian */                                              \
                                                                                                                                   \
            /* 17 - Breadcrumb, */                                                                                                 \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                                                                        \
                                                                                                                                   \
            /* 25 - BasicCommissioningInfoList, */                                                                                 \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      \
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                                                                              \
    }

#endif // BIGENDIAN_CPU

#define GENERATED_DEFAULTS_COUNT (3)

#define ZAP_TYPE(type) ZCL_##type##_ATTRIBUTE_TYPE
#define ZAP_LONG_DEFAULTS_INDEX(index)                                                                                             \
    {                                                                                                                              \
        (uint8_t *) (&generatedDefaults[index])                                                                                    \
    }
#define ZAP_MIN_MAX_DEFAULTS_INDEX(index)                                                                                          \
    {                                                                                                                              \
        (uint8_t *) (&minMaxDefault[index])                                                                                        \
    }
#define ZAP_EMPTY_DEFAULT()                                                                                                        \
    {                                                                                                                              \
        (uint16_t) 0                                                                                                               \
    }
#define ZAP_SIMPLE_DEFAULT(x)                                                                                                      \
    {                                                                                                                              \
        (uint16_t) x                                                                                                               \
    }

// This is an array of EmberAfAttributeMinMaxValue structures.
#define GENERATED_MIN_MAX_DEFAULT_COUNT 0
#define GENERATED_MIN_MAX_DEFAULTS                                                                                                 \
    {                                                                                                                              \
    }

#define ZAP_ATTRIBUTE_MASK(mask) ATTRIBUTE_MASK_##mask
// This is an array of EmberAfAttributeMetadata structures.
#define GENERATED_ATTRIBUTE_COUNT 14
#define GENERATED_ATTRIBUTES                                                                                                       \
    {                                                                                                                              \
                                                                                                                                   \
        /* Endpoint: 0, Cluster: OTA Software Update Provider (client) */                                                          \
        { 0xFFFD, ZAP_TYPE(INT16U), 2, ZAP_ATTRIBUTE_MASK(CLIENT), ZAP_SIMPLE_DEFAULT(1) }, /* ClusterRevision */                  \
                                                                                                                                   \
            /* Endpoint: 0, Cluster: OTA Software Update Requestor (server) */                                                     \
            { 0x0001, ZAP_TYPE(OCTET_STRING), 17, ZAP_ATTRIBUTE_MASK(WRITABLE),                                                    \
              ZAP_LONG_DEFAULTS_INDEX(0) },                            /* default ota provider */                                  \
            { 0x0002, ZAP_TYPE(BOOLEAN), 1, 0, ZAP_EMPTY_DEFAULT() },  /* update possible */                                       \
            { 0xFFFD, ZAP_TYPE(INT16U), 2, 0, ZAP_SIMPLE_DEFAULT(1) }, /* ClusterRevision */                                       \
                                                                                                                                   \
            /* Endpoint: 0, Cluster: General Commissioning (server) */                                                             \
            { 0x0000, ZAP_TYPE(INT64U), 8, ZAP_ATTRIBUTE_MASK(WRITABLE), ZAP_LONG_DEFAULTS_INDEX(17) }, /* Breadcrumb */           \
            { 0x0001, ZAP_TYPE(ARRAY), 254, 0, ZAP_LONG_DEFAULTS_INDEX(25) }, /* BasicCommissioningInfoList */                     \
            { 0xFFFD, ZAP_TYPE(INT16U), 2, 0, ZAP_SIMPLE_DEFAULT(0x0001) },   /* ClusterRevision */                                \
                                                                                                                                   \
            /* Endpoint: 0, Cluster: Network Commissioning (server) */                                                             \
            { 0xFFFD, ZAP_TYPE(INT16U), 2, 0, ZAP_SIMPLE_DEFAULT(1) }, /* ClusterRevision */                                       \
                                                                                                                                   \
            /* Endpoint: 0, Cluster: Operational Credentials (server) */                                                           \
            { 0x0001, ZAP_TYPE(ARRAY), 0, ZAP_ATTRIBUTE_MASK(EXTERNAL_STORAGE), ZAP_EMPTY_DEFAULT() }, /* fabrics list */          \
            { 0x0002, ZAP_TYPE(INT8U), 1, 0, ZAP_EMPTY_DEFAULT() },                                    /* SupportedFabrics */      \
            { 0x0003, ZAP_TYPE(INT8U), 1, 0, ZAP_EMPTY_DEFAULT() },                                    /* CommissionedFabrics */   \
            { 0x0004, ZAP_TYPE(ARRAY), 0, ZAP_ATTRIBUTE_MASK(EXTERNAL_STORAGE),                                                    \
              ZAP_EMPTY_DEFAULT() }, /* TrustedRootCertificates */                                                                 \
            { 0x0005, ZAP_TYPE(FABRIC_IDX), 0, ZAP_ATTRIBUTE_MASK(EXTERNAL_STORAGE),                                               \
              ZAP_EMPTY_DEFAULT() },                                   /* CurrentFabricIndex */                                    \
            { 0xFFFD, ZAP_TYPE(INT16U), 2, 0, ZAP_SIMPLE_DEFAULT(1) }, /* ClusterRevision */                                       \
    }

// This is an array of EmberAfCluster structures.
#define ZAP_ATTRIBUTE_INDEX(index) ((EmberAfAttributeMetadata *) (&generatedAttributes[index]))

// Cluster function static arrays
#define GENERATED_FUNCTION_ARRAYS

#define ZAP_CLUSTER_MASK(mask) CLUSTER_MASK_##mask
#define GENERATED_CLUSTER_COUNT 5
#define GENERATED_CLUSTERS                                                                                                         \
    {                                                                                                                              \
        {                                                                                                                          \
            0x0029, ZAP_ATTRIBUTE_INDEX(0), 1, 2, ZAP_CLUSTER_MASK(CLIENT), NULL                                                   \
        }, /* Endpoint: 0, Cluster: OTA Software Update Provider (client) */                                                       \
            {                                                                                                                      \
                0x002A, ZAP_ATTRIBUTE_INDEX(1), 3, 20, ZAP_CLUSTER_MASK(SERVER), NULL                                              \
            }, /* Endpoint: 0, Cluster: OTA Software Update Requestor (server) */                                                  \
            {                                                                                                                      \
                0x0030, ZAP_ATTRIBUTE_INDEX(4), 3, 264, ZAP_CLUSTER_MASK(SERVER), NULL                                             \
            }, /* Endpoint: 0, Cluster: General Commissioning (server) */                                                          \
            {                                                                                                                      \
                0x0031, ZAP_ATTRIBUTE_INDEX(7), 1, 2, ZAP_CLUSTER_MASK(SERVER), NULL                                               \
            }, /* Endpoint: 0, Cluster: Network Commissioning (server) */                                                          \
            {                                                                                                                      \
                0x003E, ZAP_ATTRIBUTE_INDEX(8), 6, 4, ZAP_CLUSTER_MASK(SERVER), NULL                                               \
            }, /* Endpoint: 0, Cluster: Operational Credentials (server) */                                                        \
    }

#define ZAP_CLUSTER_INDEX(index) ((EmberAfCluster *) (&generatedClusters[index]))

// This is an array of EmberAfEndpointType structures.
#define GENERATED_ENDPOINT_TYPES                                                                                                   \
    {                                                                                                                              \
        { ZAP_CLUSTER_INDEX(0), 5, 292 },                                                                                          \
    }

// Largest attribute size is needed for various buffers
#define ATTRIBUTE_LARGEST (401)

// Total size of singleton attributes
#define ATTRIBUTE_SINGLETONS_SIZE (0)

// Total size of attribute storage
#define ATTRIBUTE_MAX_SIZE (292)

// Number of fixed endpoints
#define FIXED_ENDPOINT_COUNT (1)

// Array of endpoints that are supported, the data inside
// the array is the endpoint number.
#define FIXED_ENDPOINT_ARRAY                                                                                                       \
    {                                                                                                                              \
        0x0000                                                                                                                     \
    }

// Array of profile ids
#define FIXED_PROFILE_IDS                                                                                                          \
    {                                                                                                                              \
        0x0103                                                                                                                     \
    }

// Array of device ids
#define FIXED_DEVICE_IDS                                                                                                           \
    {                                                                                                                              \
        0                                                                                                                          \
    }

// Array of device versions
#define FIXED_DEVICE_VERSIONS                                                                                                      \
    {                                                                                                                              \
        1                                                                                                                          \
    }

// Array of endpoint types supported on each endpoint
#define FIXED_ENDPOINT_TYPES                                                                                                       \
    {                                                                                                                              \
        0                                                                                                                          \
    }

// Array of networks supported on each endpoint
#define FIXED_NETWORKS                                                                                                             \
    {                                                                                                                              \
        0                                                                                                                          \
    }

// This is an array of EmberAfManufacturerCodeEntry structures for clusters.
#define GENERATED_CLUSTER_MANUFACTURER_CODE_COUNT (0)
#define GENERATED_CLUSTER_MANUFACTURER_CODES                                                                                       \
    {                                                                                                                              \
        {                                                                                                                          \
            0x00, 0x00                                                                                                             \
        }                                                                                                                          \
    }

// This is an array of EmberAfManufacturerCodeEntry structures for attributes.
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODE_COUNT (0)
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODES                                                                                     \
    {                                                                                                                              \
        {                                                                                                                          \
            0x00, 0x00                                                                                                             \
        }                                                                                                                          \
    }
