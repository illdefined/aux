#pragma once
#ifndef AUX_BITSET_H
#define AUX_BITSET_H

#include "types.h"

static void bitset_set(word *bs, word idx) {
	bs[idx / (sizeof word * 8)] |= WORD_C(1) << idx % (sizeof word * 8);
}

static void bitset_clr(word *bs, word idx) {
	bs[idx / (sizeof word * 8)] &= ~(WORD_C(1) << idx % (sizeof word * 8));
}

static bool bitset_tst(const word *bs, word idx) {
	return bs[idx / (sizeof word * 8)] & (WORD_C(1) << idx % (sizeof word * 8));
}

#endif
