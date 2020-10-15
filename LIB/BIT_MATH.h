#ifndef _MATH_H
#define _MATH_H


#define SETBIT(REG, BITNO)  (REG) |= (1 << (BITNO))
#define CLRBIT(REG, BITNO)  (REG) &= ~(1 << (BITNO))
#define TOGBIT(REG, BITNO)  (REG) ^= (1 << (BITNO))
#define GETBIT(REG, BITNO)  ((REG) >> (BITNO)) & 0x01



#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0)    CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0)    CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)

#endif