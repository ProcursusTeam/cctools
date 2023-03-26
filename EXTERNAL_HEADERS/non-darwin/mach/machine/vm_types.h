#pragma once

#include <stdint.h>

typedef unsigned int natural_t;
typedef int integer_t;

#ifdef __LP64__
typedef uintptr_t vm_size_t;
typedef uintptr_t vm_offset_t;
#else
typedef natural_t vm_size_t;
typedef natural_t vm_offset_t;
#endif
