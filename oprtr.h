#pragma once
#ifndef OPRTR_H
#define OPRTR_H

/**
 * Calculate size in bits.
 *
 * @param a type or variable
 * @return size in bits
 */
#define bits(a) (sizeof (a) * 8)

/**
 * Swap operands.
 *
 * @param a first operand
 * @param b second operand
 */
#define xchg(a, b) if (&(a) != &(b)) { \
	(a) ^= (b); \
	(b) ^= (a); \
	(a) ^= (b); \
}

/**
 * Bitwise rotation to the left.
 *
 * @param value operand
 * @param shift shift
 * @return shifted value
 */
#define rotl(value, shift) \
	((value) << ((shift) & (bits(value) - 1) | ((value) >> (bits(value) - ((shift) & (bits(value) - 1))))

/**
 * Bitwise rotation to the right.
 *
 * @param value operand
 * @param shift shift
 * @return shifted value
 */
#define rotr(value, shift) \
	((value) >> ((shift) & (bits(value) - 1) | ((value) << (bits(value) - ((shift) & (bits(value) - 1))))

#endif
