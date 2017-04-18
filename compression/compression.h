/**                                                                     
 *  /file gusimplewhiteboard/compression.h
 *                                                                      
 *  Created by Carl Lusty in 2017.                                      
 *  Copyright (c) 2017 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

#ifndef gusimplewhiteboard_compression_h
#define gusimplewhiteboard_compression_h

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

enum gswc_supported_types
{
        Type_Bool,              ///< Bool conversion type

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

        GSWC_NUM_TYPES          ///< number of types
};

//gswc_get_compressed_size

//gswc_compress
    //static compression for C standard types
    //C++ class files should include a compress function that calls this for their standard types
    //
    //
//gswc_decompress



}

#endif //gusimplewhiteboard_compression_h
