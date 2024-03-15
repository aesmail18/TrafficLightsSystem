/*
 *===========================================================================================
 *	@project	Service
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		STD_TYPES.h
 *	@version	1.0.0
 *	@brief		Redefine the data types and error states.
 *	@fun		functions: ...............................................................
 *	@create		15 Jan 2024		11:13
 *	@author		Ahmed Esmail
 *	@last		Last change: redefine the null pointer @ 15 Jan 2024	11:20
 *===========================================================================================
 */

#ifndef  STD_TYPES_H
#define  STD_TYPES_H

typedef   unsigned char      uint8  ;
typedef   unsigned short int uint16 ;
typedef   unsigned long  int uint32 ;
typedef   signed char        sint8  ;
typedef   signed short int   sint16 ;
typedef   signed long  int   sint32 ;
typedef   float              float32 ;
typedef   double             float64 ;
typedef   long double        float128 ;


typedef enum  
{
	EOK,
	ENOK,
	PARAMRETER_OUT_RANGE,
	PARAMERTE_NULL_PTR
	
}tenuErrrorStatus;

#define NULL_PTR (void *) 0

#endif



