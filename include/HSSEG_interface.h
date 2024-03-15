/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		HSSEG
 *	@version	1.0.0
 *	@brief		Public Function.
 *	@fun		functions: init, display, and count.
 *	@create		14 Jan 2024		11:20
 *	@author		Ahmed Esmail
 *	@last		Last change: create the file  @ 14 Jan 2024	11:30
 *===========================================================================================
 */

#ifndef HSSEG_INTERFACE_H_
#define HSSEG_INTERFACE_H_

void HSSEG_Init(void);
void HSSEG_DisplayNumSeg1(uint8 copy_u16Num);
void HSSEG_DisplayNumSeg2(uint8 copy_u16Num);
void HSSEG_DisplayDesCount(uint8 copy_u16StartNum);


#endif /* HSSEG_INTERFACE_H_ */
