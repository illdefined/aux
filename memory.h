#pragma once
#ifndef AUX_MEMORY_H
#define AUX_MEMORY_H

#include <stdint.h>
#include <sys/mman.h>

#define align(size, alignment) (((uintptr_t) (size) + (uintptr_t) (alignment) - 1ul) & ~((uintptr_t) (alignment) - 1ul))
#define alloc(size) mmap((void *) 0, (size), PROT_READ | PROT_WRITE, MAP_ANON, -1, 0)

#endif
