/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		NVIC
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Program file for NVIC.
 *	@fun		functions: Driver functions.
 *	@create		17 Jan 2024		11:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Write body of SetInterruptPriority function @ 17 Jan 2024	12:15
 *===========================================================================================
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "MNVIC_prv.h"
#include "MNVIC_int.h"
#include "MNVIC_conf.h"

uint8 Global_u8IPR=0;

void NVIC_voidInterruptEnable(uint8 position)
{
	NVIC->ISER[position/32] |= (1 << (position%32));
}
void NVIC_voidInterruptDisable(uint8 position)
{
	NVIC->ICER[position/32] |= (1 << (position%32));
}

void NVIC_voidSetPendingFlag(uint8 position)
{
	NVIC->ISPR[position/32] |= (1 << (position%32));
}
void NVIC_voidClrPendingFlag(uint8 position)
{
	NVIC->ICPR[position/32] |= (1 << (position%32));
}

void MNVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode)
{
	uint32 Local_Var=0;
	Global_u8IPR = Copy_uddtGroupMode;

	AIRCR=VECTKEY;
	Local_Var = (VECTKEY) | (Copy_uddtGroupMode<<8) ;

	AIRCR = Local_Var;


}

void MNVIC_VoidSetInterruptPriority(uint8 Copy_u8IntPos,uint8 Copy_u8GroupNum,uint8 Copy_u8SubGroupNum)
{
	switch (Global_u8IPR)
	{
	case Group16Sub0: NVIC->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<4 ;
	break;

	case Group8Sub2:NVIC->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<5 |Copy_u8SubGroupNum<<4 ;
	break;

	case Group4Sub4:NVIC ->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<6 |Copy_u8SubGroupNum<<4 ;
	break;

	case Group2Sub8:NVIC ->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<7 |Copy_u8SubGroupNum<<4 ;
	break;

	case Group0Sub16:NVIC ->IPR[Copy_u8IntPos]= Copy_u8SubGroupNum<<4 ;
	break;
	}
}
