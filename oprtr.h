#pragma once
#ifndef OPRTR_H
#define OPRTR_H

#define bits(a) (sizeof (a) * 8)

#define xchg(a, b) if (&(a) != &(b)) { \
	(a) ^= (b); \
	(b) ^= (a); \
	(a) ^= (b); \
}

#define rotl(value, shift) \
	((value) << ((shift) & (bits(value) - 1) | ((value) >> (bits(value) - ((shift) & (bits(value) - 1))))

#define rotr(value, shift) \
	((value) >> ((shift) & (bits(value) - 1) | ((value) << (bits(value) - ((shift) & (bits(value) - 1))))

#endif
