#pragma once
#ifndef AUX_SALLOC_H
#define AUX_SALLOC_H

#include "memory.h"

/**
 * Allocate memory using alloc().
 *
 * @param len size
 * @return pointer to the memory or MAP_FAILED on error
 */
static void *salloc(word len) {
	word *ptr = alloc(len += sizeof (word));

	if (ptr != MAP_FAILED)
		*(ptr++) = len;

	return ptr;
}

/**
 * Free memory allocated by salloc().
 *
 * @param ptr pointer to the memory
 * @return true on success or false on failure
 */
static bool sfree(void *ptr) {
	word *mem = ptr;
	return munmap(--mem, *mem) ? false : true;
}

#endif
