/*
 * SevenSEG4.c
 *
 * Created: 8/11/2025 12:35:41 AM
 * Author : nanav
 */ 

#include <avr/io.h>
#include "DIO.h"

void Seven_seg4_init(char port,char ch )
{
	if (ch == 0)
	{
		DIO_Setpindir(port,0,1);
		DIO_Setpindir(port,1,1);
		DIO_Setpindir(port,2,1);
		DIO_Setpindir(port,3,1);
	}
	else
	{
		DIO_Setpindir(port,4,1);
		DIO_Setpindir(port,5,1);
		DIO_Setpindir(port,6,1);
		DIO_Setpindir(port,7,1);
	}
	
}


void  Seven_seg4_write(char port,char val,char cc)
{
	
	if (cc ==  0)
	{
		DIO_Writelownibble(port,val);
	}
	else
	{
		DIO_Writehighnibble(port,val);
		
	}
}
