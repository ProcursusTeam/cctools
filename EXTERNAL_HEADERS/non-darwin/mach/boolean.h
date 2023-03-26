#pragma once

#if defined(__x86_64__)
typedef unsigned int boolean_t;
#elif defined(__i386__)
typedef int boolean_t;
#elif defined(__arm__) || defined(__arm64__)
typedef int boolean_t;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif
