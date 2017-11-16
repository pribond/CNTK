//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//
#pragma once

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the IMAGEWRITER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// IMAGEWRITER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef _WIN32
#if defined(IMAGEWRITER_EXPORTS)
#define IMAGEWRITER_API __declspec(dllexport)
#elif defined(IMAGEWRITER_LOCAL)
#define IMAGEWRITER_API
#else
#define IMAGEWRITER_API __declspec(dllimport)
#endif
#else
#define IMAGEWRITER_API
#endif

#include <vector>

namespace Microsoft { namespace MSR { namespace CNTK {

    // TODO: ::CNTK::DataType can be used instead but header only CNTKLibrary.h include is broken.
    enum class DataType : unsigned int
    {
        Float = 1,
        Double = 2
    };

    extern "C" IMAGEWRITER_API void EncodeImageAsPNG(void* matrix, DataType dtype, int height, int width, int depth, std::vector<unsigned char>& buffer);

} } }
