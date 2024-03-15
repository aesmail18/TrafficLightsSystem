/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		NVIC
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Interface file for NVIC.
 *	@fun		functions: Public functions.
 *	@create		17 Jan 2024		11:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Create the interface file @ 17 Jan 2024	11:50
 *===========================================================================================
 */

#ifndef MNVIC_INT_H_
#define MNVIC_INT_H_

typedef enum
{
 Group16Sub0=3,
 Group8Sub2,
 Group4Sub4,
 Group2Sub8,
 Group0Sub16
}MNVIC_Group_t;

void NVIC_voidInterruptEnable(uint8 position);
void NVIC_voidInterruptDisable(uint8 position);
void NVIC_voidSetPendingFlag(uint8 position);
void NVIC_voidClrPendingFlag(uint8 position);
void MNVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode); //AIRCR --> how many groups and sub groubs in our micro?
void MNVIC_VoidSetInterruptPriority(uint8 Copy_u8IntPos,uint8 Copy_u8GroupNum,uint8 Copy_u8SubGroupNum) ;

#endif /* MNVIC_INT_H_ */
