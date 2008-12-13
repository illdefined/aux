#pragma once
#ifndef AUX_TICKS_H
#define AUX_TICKS_H

#include <sys/time.h>

#include "types.h"

static word ticks() {
	register word cnt;

/* x86 */
#if defined(__i386__) || defined(__x86_64__)
	/* Read time stamp counter */
	register u32 low, high;
	__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
	cnt = (word) low | (word) high << 32;

/* SPARC */
#elif defined(__sparc__)
	/* Read from tick register */
	__asm__ volatile ("rd %%tick, %0" : "=r" (cnt));

/* PowerPC */
#elif defined(__powerpc__)
	/* Read time base */
	__asm__ volatile ("mftb %0" : "=r" (cnt));

/* PA-RISC */
#elif defined(__hppa__)
	/* Read interval timer from control register */
	__asm__ volatile ("mfctl 16, %0" : "=r" (cnt));

/* Alpha */
#elif defined(__alpha__)
	/* Read process cycle counter */
	__asm__ volatile ("rpcc %0" : "=r" (cnt));

/* IA-64 */
#elif defined(__ia64__)
	/* Read time counter */
	__asm__ volatile ("mov %0 = ar.itc" : "=r" (cnt));

/* Generic architecture-independent mechanism */
#else
#warning "No hardware tick counter available!"
	struct timeval tv;
	gettimeofday(&tv, (struct timezone *) 0);
	cnt = (word) tv.tv_sec * WORD_C(1000000)
	    + (word) tv.tv_usec;
#endif

	return cnt;
}

#endif
