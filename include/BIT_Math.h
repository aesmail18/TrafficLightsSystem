/*
 *===========================================================================================
 *	@project	Service
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		BIT_MATH.h
 *	@version	1.0.0
 *	@brief		Define macros for bit minpulation.
 *	@fun		functions: SET, GET, Clear, Toggle, and Write.
 *	@create		15 Jan 2024		11:20
 *	@author		Ahmed Esmail
 *	@last		Last change: Define a macro to write a value on bit  @ 15 Jan 2024	11:30
 *===========================================================================================
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Bit-Math macros*/
#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

#define WRITE_BIT(REG , BIT, VAL)    CLR_BIT(REG,BIT) | (val << BIT)

#endif 
