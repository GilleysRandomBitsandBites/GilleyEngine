#ifndef GIL_PLATFORM_H
#define GIL_PLATFORM_H

#endif
//
// NOTE:
//
// Define pre-processor macros for DLL export import, and
// system macros
//

#ifdef _WIN32
    #define GIL_SYS_WINDOWS
    //defined to disable <windows.h> from defining the min and max macros
    #ifndef NOMIMMAX
    #define NOMINMAX
    #endif
#elif defined (__linux__)
    #define GIL_SYS_LINUX
#elif defined (__APPLE__)
    #define GIL_SYS_MACOS
#endif

#ifndef GIL_STATIC_BUILD
#ifdef GIL_SYS_WINDOWS
   #ifdef GIL_NONCLIENT_BUILD
        #define GIL_API __declspec(dllexport)
   #else
        #define GIL_API __declspec(dllimport)
   #endif
   //Visual C++ compiler warning C4251 disable
   #ifdef __MSC_VER
       #pragma warning(disable : 4251)
   #endif 
#elif defined(GIL_SYS_LINUX) || defined(GIL_SYS_MACOS)
   #ifdef __GNUC__ >= 4
           #define GIL_API_attribute__ ((__visibility__("default")))
   #else
#define GIL_API GIL_API
#endif

#endif
#endif

