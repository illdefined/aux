#pragma once
#ifndef AUX_BITSET_H
#define AUX_BITSET_H

#include "types.h"
#include "oprtr.h"

static void bitset_set(word *bs, word idx) {
	bs[idx / bits(word)] |= WORD_C(1) << idx % bits(word);
}

static void bitset_clr(word *bs, word idx) {
	bs[idx / bits(word)] &= ~(WORD_C(1) << idx % bits(word));
}

static bool bitset_tst(const word *bs, word idx) {
	return bs[idx / bits(word)] & (WORD_C(1) << idx % bits(word));
}

#endif
