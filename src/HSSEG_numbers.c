/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver     HSSEG
 *	@version	1.0.0
 *  @layer      HAL
 *	@brief		7 Segment numbers
 *	@fun		functions: Array of numbers
 *	@create		14 Mar 2024		13:30
 *	@author		Ahmed Esmail
 *	@last		Last change: Finish the main and write some handy comments @ 15 Mar 2024	11:21
 *===========================================================================================
 */


#include "STD_Types.h"
#include "BIT_Math.h"
#include "MGPIO_int.h"

#include "HSSEG_interface.h"

uint16 numbers[] =
{
	//0   1    2    3    4    5    6    7    8    9
	0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};



