/*
 * LCD.c
 *
 * Created: 8/24/2025 9:45:08 PM
 * Author : Nader
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"



static void enable(void)
{
	DIO_Writepin(LCD_Controlport,EN,1);
	_delay_ms(2);
	DIO_Writepin(LCD_Controlport,EN,0);
	_delay_ms(2);	
}


void LCD_Sendchar(char data)
{
	#if Mode
	DIO_Writeport(LCD_Dataport,data);
	DIO_Writepin(LCD_Controlport,Rs,1);
	enable();
	#else
	DIO_Writehighnibble(LCD_Dataport,data >> 4);
	DIO_Writepin(LCD_Controlport,Rs,1);
	enable();
	DIO_Writehighnibble(LCD_Dataport,data &0x0F);
	DIO_Writepin(LCD_Controlport,Rs,1);
	enable();

	#endif
	_delay_ms(1);
	
	
}

void LCD_Sendcmd(char cmd)
{
	#if Mode
	DIO_Writeport(LCD_Dataport,cmd);
	DIO_Writepin(LCD_Controlport,Rs,0);
	enable();
	_delay_ms(1);
	#else
	DIO_Writehighnibble(LCD_Dataport,cmd >> 4);
	DIO_Writepin(LCD_Controlport,Rs,0);
	enable();
	DIO_Writehighnibble(LCD_Dataport,cmd &0x0F);
	DIO_Writepin(LCD_Controlport,Rs,0);
	enable();

	#endif
	_delay_ms(1);
}

void LCD_Clear_Screen(void)
{
	
	LCD_Sendcmd(CLR_SCREEN);
	_delay_ms(10);
}


void LCD_Init(void)
{
	_delay_ms(200);
	DIO_Setpindir(LCD_Controlport,RW,1);
	DIO_Writepin(LCD_Controlport,RW,0);
	
	#if Mode
	DIO_Setportdir(LCD_Dataport,1);
	DIO_Setpindir(LCD_Controlport,EN,1);
	DIO_Setpindir(LCD_Controlport,Rs,1);
	LCD_Sendcmd(FUNCTION_SET_8BIT_2LINE);    //8bitmode//
	LCD_Sendcmd(CURSOR_ON_BLINK_OFF);
	LCD_Sendcmd(CLR_SCREEN);
	LCD_Sendcmd(ENTRY_MODE);
	#else
	DIO_Setpindir(LCD_Dataport,4,1);
	DIO_Setpindir(LCD_Dataport,5,1);
	DIO_Setpindir(LCD_Dataport,6,1);
	DIO_Setpindir(LCD_Dataport,7,1);
	DIO_Setpindir(LCD_Controlport,EN,1);
	DIO_Setpindir(LCD_Controlport,Rs,1);
	LCD_Sendcmd(RETURN_HOME);
	_delay_ms(10);
	LCD_Sendcmd(FUNCTION_SET_4BIT_2LINE);    //4bitmode//
	_delay_ms(1);
	LCD_Sendcmd(CURSOR_ON_BLINK_OFF);
	_delay_ms(1);
	LCD_Sendcmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_Sendcmd(ENTRY_MODE);
	_delay_ms(1);
	
	#endif
	    
}

void LCD_Sendstring(char *ptr)
{
	while(*ptr != 0)
	{
		LCD_Sendchar(*ptr);
		ptr++;
	}
}


void LCD_movecursor(char row,char col)
{
	char data ;
	if (row<1 || row >2	|| col<1 || col>16)
	{
		data = 0x80;
	}
	else if (row == 1)
	{
		data = 0x80 + col - 1;
	}
	else if (row == 2)
	{
		data = 0xC0 + col - 1;
	}
	LCD_Sendcmd(data);
}