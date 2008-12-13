#pragma once
#ifndef AUX_SALLOC_H
#define AUX_SALLOC_H

#include "memory.h"

static void *salloc(word len) {
	word *ptr = alloc(len += sizeof (word));

	if (ptr != MAP_FAILED)
		*(ptr++) = len;

	return ptr;
}

static bool sfree(void *ptr) {
	word *mem = ptr;
	return munmap(--mem, *mem) ? false : true;
}

#endif
