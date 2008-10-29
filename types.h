#pragma once
#ifndef AUX_TYPES_H
#define AUX_TYPES_H

/* Propagate boolean type */
#include <stdbool.h>

#include <stdint.h>

/* Integral types */
typedef uintptr_t word;
typedef   uint8_t   u8;
typedef  uint16_t  u16;
typedef  uint32_t  u32;
typedef  uint64_t  u64;

typedef    int8_t   i8;
typedef   int16_t  i16;
typedef   int32_t  i32;
typedef   int64_t  i64;

/* Limit definitions */
#define WORD_MAX UINTPTR_MAX
#define   U8_MAX   UINT8_MAX
#define  U16_MAX  UINT16_MAX
#define  U32_MAX  UINT32_MAX
#define  U64_MAX  UINT64_MAX

#define   I8_MIN    INT8_MIN
#define  I16_MIN   INT16_MIN
#define  I32_MIN   INT32_MIN
#define  I64_MIN   INT64_MIN

#define   I8_MAX    INT8_MAX
#define  I16_MAX   INT16_MAX
#define  I32_MAX   INT32_MAX
#define  I64_MAX   INT64_MAX

/* Constant expression macros */
#define WORD_C(c) ((word) UINTMAX_C(c))
#define   U8_C(c)   UINT8_C(c)
#define  U16_C(c)  UINT16_C(c)
#define  U32_C(c)  UINT32_C(c)
#define  U64_C(c)  UINT64_C(c)

#define   I8_C(c)    INT8_C(c)
#define  I16_C(c)   INT16_C(c)
#define  I32_C(c)   INT32_C(c)
#define  I64_C(c)   INT64_C(c)

#endif
