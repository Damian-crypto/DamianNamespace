#ifndef DAMIAN_TOOLKIT_H
#define DAMIAN_TOOLKIT_H

#define OS_VERSION windows
#define VERSION_OK __cplusplus >= 201103L || __cplusplus >= 199711L

#if VERSION_OK
#include "math.h"
#include "string.h"
#include "functions.h"
#else
#error Damian namespace does not work if C++ version is less than 11(201103L)
#endif

#endif
