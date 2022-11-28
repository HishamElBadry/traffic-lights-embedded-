/*
 * App.c
 *
 * Created: 11/4/2022 3:45:29 PM
 *  Author: Hisham Elbadry
 */ 
#define F_CPU 16000000
#include "App.h"	
u8 static stateCounter =0;
u16 static CTC_Counter=0;	
u8 flag=0;
u8 flag_2=0;
u8 flag_init=1;
	
u8 static stateCounter_t =0;
u16 static CTC_Counter_t=0;
u8 state=0;
bool app_init()
{
	/*Set Direction pins*/
	
	MDIO_SetPortDirection(MDIO_PORTA,PORT_OUTPUT);
	
	MDIO_SetPortDirection(MDIO_PORTB,PORT_OUTPUT);
	
	MDIO_SetPinDirection(PIN2,MDIO_PORTD,PIN_INPUT);
	
	
		
	/*initialize timer and interrupt */
	MTIMER0_Init();
	MGIE_Enable();
	MEXTI0_Init();
	
	/*Setting OC0 of CTC*/
	MTIMER0_SetCTC(125);	
	
	//set initialization to PIN
	MDIO_SetPinValue(PIN2,MDIO_PORTD,PIN_HIGH);
	MDIO_ReadPin(PIN2,MDIO_PORTD,&state);
	if (state ==1)
	{
		return true;
	}
	return false;
}

bool Normal_Mode()
{
	if (flag_init == 1)
	{
		Led_ON(MDIO_PORTA,PIN0);
		Led_ON(MDIO_PORTB,PIN0);
	}
	if (flag ==1)
	{
		Led_BLINKING(MDIO_PORTA,PIN1);
		Led_BLINKING(MDIO_PORTB,PIN1);
	}
	if (CTC_Counter == 625 && flag_2==1)
	{
		stateCounter=0;
		flag_2=0;
	}

	if(CTC_Counter==625 && stateCounter ==0)
	{
		flag_init=0;
		Led_OFF(MDIO_PORTA,PIN0);
		Led_OFF(MDIO_PORTB,PIN0);
		flag=1;
		CTC_Counter=0;		
		stateCounter++;
	}
	else if(CTC_Counter==625 && stateCounter ==1)
	{
		flag =0;
		Led_OFF(MDIO_PORTA,PIN1);
		Led_OFF(MDIO_PORTB,PIN1);
		
		Led_ON(MDIO_PORTA,PIN2);
		Led_ON(MDIO_PORTB,PIN2);
		
		CTC_Counter=0;
		stateCounter++;
	}
	else if( CTC_Counter==625 && stateCounter == 2)
	{
		Led_OFF(MDIO_PORTA,PIN2);
		Led_OFF(MDIO_PORTB,PIN2);
		flag=1;
		CTC_Counter=0;
		stateCounter++;
	}
	else if(CTC_Counter==625 && stateCounter ==3)
	{
		flag=0;
		Led_OFF(MDIO_PORTA,PIN1);
		Led_OFF(MDIO_PORTB,PIN1);
		
		Led_ON(MDIO_PORTA,PIN0);
		Led_ON(MDIO_PORTB,PIN0);
		
		CTC_Counter=0;
		flag_2=1;
	}
		CTC_Counter++;
		
	if (flag_init ==1 || stateCounter>3 ||stateCounter<0 )
	{
		return false;	
	}else {
		return true;
	}
}

bool Pedesterian_Mode()
{	
		if(stateCounter !=3 && flag_init ==0)
		{
			stateCounter =2;
			CTC_Counter=625;
			Normal_Mode();
			return true;
		} else {
			return false;
		}
		
}


void app_start()
{
	
	MTIMER0_CTC_CALLBACK(Normal_Mode);
	MEXTI0_CallBack(Pedesterian_Mode);
}



void Test_drivers()
{
	if(CTC_Counter_t==250 && stateCounter_t ==0)
	{
		Led_ON(MDIO_PORTA,PIN0);
		stateCounter_t++;
		CTC_Counter_t=0;
		
	}
	else if(CTC_Counter_t==250 && stateCounter_t ==1)
	{
		Led_OFF(MDIO_PORTA,PIN0);
		stateCounter_t=0;
		CTC_Counter_t=0;
	}
	CTC_Counter_t++;
}
