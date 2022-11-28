
/*
 * MLED_Program.c
 *
 * Created: 11/8/2022 8:51:41 PM
 *  Author: Hisham Elbadry
 */ 


#ifndef HAL_MLED_PROGRAM_H_
#define HAL_MLED_PROGRAM_H_
#define  F_CPU 16000000
#include "util/delay.h"
#include "MLED_Interface.h"


void Led_ON (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber)
{
	MDIO_SetPinValue(Copy_u8PinNumber,Copy_u8PortNumber,PIN_HIGH);
}

void Led_BLINKING (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber)
{
	MDIO_TogglePin(Copy_u8PinNumber,Copy_u8PortNumber);
}

void Led_OFF (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber)
{
	MDIO_SetPinValue(Copy_u8PinNumber,Copy_u8PortNumber,PIN_LOW);
}


#endif