/*
The MIT License (MIT)

Copyright (c) 2016 Liav Turkia

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*/
#pragma once
#ifndef MACE_CORE_CONFIGURE_H
#define MACE_CORE_CONFIGURE_H

/*
=======================================
Meta variables
=======================================
*/
#define MACE_VERSION 0.0.1
#define MACE_VERSION_MAJOR 0
#define MACE_VERSION_MINOR 0
#define MACE_VERSION_PATCH 1

/* #undef MACE_TESTS */
#define MACE_DEMOS 1

/*
=======================================
Libraries
=======================================
*/
/* #undef MACE_POSIX */

#define MACE_WINAPI 1

#if !defined(MACE_POSIX) && !defined(MACE_WINAPI)
#	error "Error in configuration process: this system is unsupported. It must have either windows.h or unistd.h"
#elif defined(MACE_POSIX) && defined(MACE_WINAPI)
#	error "Error in configuration process: this system has been detected to have both Winapi and POSIX."
#endif

/*
=======================================
Operating System
=======================================
*/
/* #undef MACE_OSX */
#define MACE_WINDOWS 1
/* #undef MACE_UNIX */

#if !(defined(MACE_OSX)||defined(MACE_WINDOWS)||defined(MACE_UNIX))
#	error "Error in configuration process: problem detecting valid operating system: couldn't detect system"
#elif defined(MACE_OSX) && defined(MACE_WINDOWS) && defined(MACE_UNIX)
#	error "Error in configuration process: problem detecting valid operating system: multiple systems detected"
#endif

/* #undef MACE_BIG_ENDIAN */

#ifndef MACE_BIG_ENDIAN
#	define MACE_LITTLE_ENDIAN 1
#endif//MACE_BIG_ENDIAN

/* #undef MACE_SHARED_LIBS */
#define MACE_STATIC_LIBS 1

#define MACE_POINTER_SIZE 4

#if MACE_POINTER_SIZE == 4
#	define MACE_32_BIT 1
#elif MACE_POINTER_SIZE == 8
#	define MACE_64_BIT 1
#endif

#define MACE_DYNAMIC_LIBRARY_PREFIX 
#define MACE_DYNAMIC_LIBRARY_SUFFIX .dll

#endif//MACE_CORE_CONFIGURE_H
