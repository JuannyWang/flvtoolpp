/* Copyright (c) Microsoft Corporation. All rights reserved. */
/*
 * Definitions for writing byte-order and bit-order portable code.
 */

#ifndef _ENDIAN_H_
#define _ENDIAN_H_ 1

//#ifndef BYTE_ORDER
//#error You need to define BYTE_ORDER to include this file
//#endif

/* Unless stated otherwise, the bit-order is the same as the byte-order
 */
#ifndef BIT_ORDER
#define BIT_ORDER BYTE_ORDER
#endif

/* Bit definitions
 * NB: Only works for UINT32 entities
 */
#if (BIT_ORDER == BYTE_ORDER)
#define bit0 (1<<0)
#define bit1 (1<<1)
#define bit2 (1<<2)
#define bit3 (1<<3)
#define bit4 (1<<4)
#define bit5 (1<<5)
#define bit6 (1<<6)
#define bit7 (1<<7)
#define bit8 (1<<8)
#define bit9 (1<<9)
#define bit10 (1<<10)
#define bit11 (1<<11)
#define bit12 (1<<12)
#define bit13 (1<<13)
#define bit14 (1<<14)
#define bit15 (1<<15)
#define bit16 (1<<16)
#define bit17 (1<<17)
#define bit18 (1<<18)
#define bit19 (1<<19)
#define bit20 (1<<20)
#define bit21 (1<<21)
#define bit22 (1<<22)
#define bit23 (1<<23)
#define bit24 (1<<24)
#define bit25 (1<<25)
#define bit26 (1<<26)
#define bit27 (1<<27)
#define bit28 (1<<28)
#define bit29 (1<<29)
#define bit30 (1<<30)
#define bit31 (1<<31)
#else
#define bit0 (1<<(31-0))
#define bit1 (1<<(31-1))
#define bit2 (1<<(31-2))
#define bit3 (1<<(31-3))
#define bit4 (1<<(31-4))
#define bit5 (1<<(31-5))
#define bit6 (1<<(31-6))
#define bit7 (1<<(31-7))
#define bit8 (1<<(31-8))
#define bit9 (1<<(31-9))
#define bit10 (1<<(31-10))
#define bit11 (1<<(31-11))
#define bit12 (1<<(31-12))
#define bit13 (1<<(31-13))
#define bit14 (1<<(31-14))
#define bit15 (1<<(31-15))
#define bit16 (1<<(31-16))
#define bit17 (1<<(31-17))
#define bit18 (1<<(31-18))
#define bit19 (1<<(31-19))
#define bit20 (1<<(31-20))
#define bit21 (1<<(31-21))
#define bit22 (1<<(31-22))
#define bit23 (1<<(31-23))
#define bit24 (1<<(31-24))
#define bit25 (1<<(31-25))
#define bit26 (1<<(31-26))
#define bit27 (1<<(31-27))
#define bit28 (1<<(31-28))
#define bit29 (1<<(31-29))
#define bit30 (1<<(31-30))
#define bit31 (1<<(31-31))
#endif

/*
 * Macros to take care of bitfield placement within a byte.
 * It might be possible to extend these to something that
 * takes care of multibyte structures, using perhaps the
 * type ("t") parameter.  Someday.
 *
 * Note also that it is conceivable (but weird) that a compiler
 * did not allocate bitfields according to the byteorder.
 * Fix if/as necessary.
 */
#if BYTE_ORDER==BIG_ENDIAN

#define BITFIELD_2(t,a,b)               t b,a
#define BITFIELD_3(t,a,b,c)             t c,b,a
#define BITFIELD_4(t,a,b,c,d)           t d,c,b,a
#define BITFIELD_5(t,a,b,c,d,e)         t e,d,c,b,a
#define BITFIELD_6(t,a,b,c,d,e,f)       t f,e,d,c,b,a
#define BITFIELD_7(t,a,b,c,d,e,f,g)     t g,f,e,d,c,b,a
#define BITFIELD_8(t,a,b,c,d,e,f,g,h)   t h,g,f,e,d,c,b,a

#else   /*LITTLE_ENDIAN*/

#define BITFIELD_2(t,a,b)               t a,b
#define BITFIELD_3(t,a,b,c)             t a,b,c
#define BITFIELD_4(t,a,b,c,d)           t a,b,c,d
#define BITFIELD_5(t,a,b,c,d,e)         t a,b,c,d,e
#define BITFIELD_6(t,a,b,c,d,e,f)       t a,b,c,d,e
#define BITFIELD_7(t,a,b,c,d,e,f,g)     t a,b,c,d,e,f,g
#define BITFIELD_8(t,a,b,c,d,e,f,g,h)   t a,b,c,d,e,f,g,h

#endif

/* Sometimes things get byteswapped over the I/O channel
 * and you need to build constants for that.
 * ByteSwap32BitConstant (or _bs32 for short) handles that.
 *
 * Before including this file, a device driver should define
 * DEVICE_ORDER according to its own byteorder.
 * NB: If you do not define it the macro _bs32() will swap
 */
#define ByteSwap32BitConstant(_n_)  ((((_n_)&0xff)<<24) | \
                                     (((_n_)&0xff00)<<8) | \
                                     (((_n_)&0xff0000)>>8) | \
                                     (((_n_)&0xff000000)>>24))
#define ByteSwap16BitConstant(_n_)  ((((_n_)&0xff)<<8) | \
                                     (((_n_)&0xff00)>>8))
#if (BYTE_ORDER != DEVICE_ORDER)
#define _bs32(_n_) ByteSwap32BitConstant(_n_)
#define _bs16(_n_) ByteSwap16BitConstant(_n_)
#else
#define _bs32(_n_) (_n_)
#define _bs16(_n_) (_n_)
#endif
#endif /* _ENDIAN_H_ */