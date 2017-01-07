#ifndef _XMA_CORE_SYSTEM_HPP
#define _XMA_CORE_SYSTEM_HPP

#if defined(_WIN32)
    #define XMA_SYSTEM_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
#include "TargetConditionals.h"
    #if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
        #define XMA_SYSTEM_IOS
    #elif TARGET_OS_MAC
        #define XMA_SYSTEM_MACOS
    #else
        #error This Apple operating system is not supported by XMA
    #endif
#elif defined(__unix__)
#if defined(__ANDROID__)
        #define XMA_SYSTEM_ANDROID
    #elif defined(__linux__)
        #define XMA_SYSTEM_LINUX
    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        #define XMA_SYSTEM_FREEBSD
    #else
        #error This UNIX operating system is not supported by XMA
    #endif
#else
    #error This operating system is not supported by XMA
#endif

#endif
