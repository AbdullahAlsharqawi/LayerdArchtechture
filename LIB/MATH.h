

#ifndef _BIT_MATH_H
#define _BIT_MATH_H


#define SETBIT(REG, BITNO)  (REG) |= (1 << (BITNO))
#define CLRBIT(REG, BITNO)  (REG) &= ~(1 << (BITNO))
#define TOGBIT(REG, BITNO)  (REG) ^= (1 << (BITNO))
#define GETBIT(REG, BITNO)  ((REG) >> (BITNO)) & 0x01



#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0)    CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)  0b##B7##B6##B5##B4##B3##B2##B1##B0


#endif
