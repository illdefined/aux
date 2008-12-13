#pragma once
#ifndef AUX_MEMORY_H
#define AUX_MEMORY_H

#define _BSD_SOURCE

#include <stdint.h>
#include <sys/mman.h>

#include "types.h"

#define align(size, alignment) \
	(((word) (size) + (word) (alignment) - WORD_C(1)) & ~((word) (alignment) - WORD_C(1)))

#define alloc(size) \
	mmap((void *) 0, (size), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)

#endif
