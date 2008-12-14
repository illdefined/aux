#pragma once
#ifndef AUX_MEMORY_H
#define AUX_MEMORY_H

#define _BSD_SOURCE

#include <stdint.h>
#include <sys/mman.h>

#include "types.h"

/**
 * Pad size to alignment.
 *
 * @param size size to pad
 * @param alignment alignment
 * @return padded size
 */
#define align(size, alignment) \
	(((word) (size) + (word) (alignment) - WORD_C(1)) & ~((word) (alignment) - WORD_C(1)))

/**
 * Allocate memory using mmap().
 *
 * @param size size
 * @return pointer to the memory or MAP_FAILED on error
 */
#define alloc(size) \
	mmap((void *) 0, (size), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)

#endif
