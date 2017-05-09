/**                                                                     
 *  /file gusimplewhiteboard/compression.h
 *                                                                      
 *  Created by Carl Lusty in 2017.                                      
 *  Copyright (c) 2017 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

#ifndef gusimplewhiteboard_compression_h
#define gusimplewhiteboard_compression_h

#include <gusimplewhiteboard/gusimplewhiteboard.h>

#include <string.h>
#include <sys/types.h>

#ifndef __cplusplus
#include <stdbool.h>
#else
#if __cplusplus < 201103L
#include <stdbool.h>
#else
#include <cstdbool>
#endif
extern "C"
{
#endif // __cplusplus

enum gswc_supported_types
{
        Type_Bool = 0,              ///< Bool conversion type

        Type_Int8,              ///< Int8 conversion type
        Type_Int16,             ///< Int16 conversion type
        Type_Int32,             ///< Int32 conversion type
        Type_Int64,             ///< Int64 conversion type

        Type_UInt8,             ///< UInt8 conversion type
        Type_UInt16,            ///< UInt16 conversion type
        Type_UInt32,            ///< UInt32 conversion type
        Type_UInt64,            ///< UInt64 conversion type

        Type_Float,             ///< Float conversion type
        Type_Double,            ///< Double conversion type

        GSWC_NUM_TYPES,         ///< number of types
        GSWC_TYPE_NOT_SUPPORTED = -1          ///< value to return when a type doesn't support compression
};

//Index values MUST match their enum value in gswc_supported_types
const char *gswc_supported_types_stringmap[GSWC_NUM_TYPES] = 
{
    "bool",     

    "int8_t",
    "int16_t",
    "int32_t",
    "int64_t",

    "uint8_t",
    "uint16_t",
    "uint32_t",
    "uint64_t",

    "float",
    "double"/*,

    "GSWC_NUM_TYPES"          ///< number of types
        */
};

//Index values MUST match their enum value in gswc_supported_types
const size_t gswc_supported_types_sizemap[GSWC_NUM_TYPES] = 
{
    1,     //"bool"

    8,     //"int8_t"
    16,    //"int16_t"
    32,    //"int32_t"
    64,    //"int64_t"

    8,     //"uint8_t"
    16,    //"uint16_t"
    32,    //"uint32_t"
    64,    //"uint64_t"

    32,    //"float"
    64/*,    //"double"

    -1    //"GSWC_NUM_TYPES"          ///< number of types
    */
};

enum gswc_supported_types gswc_get_compressed_type_index(const char *t)
{
    for (size_t i = 0; i < GSWC_NUM_TYPES; i++)
    {
        if (strncmp(t, gswc_supported_types_stringmap[i], strlen(gswc_supported_types_stringmap[i])) == 0)
        {
            return (enum gswc_supported_types)i;
        }
    }
    return GSWC_TYPE_NOT_SUPPORTED;
}

void gswc_compress(void *dst, gu_simple_message *msg, size_t size)
{
    memcpy(dst, msg, size);    
}

void gswc_decompress(void *dst, gu_simple_message *msg, size_t size)
{
    memcpy(msg, dst, size);    
}

#ifdef __cplusplus
}
#endif

#endif //gusimplewhiteboard_compression_h
