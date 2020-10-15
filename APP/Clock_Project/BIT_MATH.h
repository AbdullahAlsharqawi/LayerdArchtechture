#ifndef _MATH_H
#define _MATH_H
	#define SETBIT(var,bit) (var) = (var) | (1<<(bit)) 
	#define CLRBIT(var,bit) (var) = (var) & ~( 1<<(bit))
	#define TOGBIT(var,bit) (var) = (var) ^ (1<<(bit))
	#define GETBIT(var,bit)  ( ( (var) & (1<<(bit) ) ) > 0) ? (1) : (0)
	#define Set_Low_Nib(var) (var) = (var) | 0X0F
	#define Clr_Low_Nib(var) (var) = (var) & 0XF0
	#define Toggle_Low_Nib(var) (var) = (var) ^ 0X0F
	#define Set_High_Nib(var) (var) = (var) | 0XF0
	#define Clr_High_Nib(var) (var) = (var) & 0X0F
	#define Toggle_High_Nib(var) (var) = (var) ^ 0XF0
	
	#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0) CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
	#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)  0b##B7##B6##B5##B4##B3##B2##B1##B0
	
#endif
