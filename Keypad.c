/*
 * Keypad.c
 *
 * Created: 8/31/2025 2:11:31 AM
 * Author : nanav
 */ 

#include <avr/io.h>
#include "DIO.h"

#define NOTPRESSED 0xff



void Keypad_Init(char port)
{
	DIO_Setpindir(port,0,1);
	DIO_Setpindir(port,1,1);
	DIO_Setpindir(port,2,1);
	DIO_Setpindir(port,3,1);
	DIO_Setpindir(port,4,0);
	DIO_Setpindir(port,5,0);
	DIO_Setpindir(port,6,0);
	DIO_Setpindir(port,7,0);
	DIO_Connectpullup(port,4,1);
	DIO_Connectpullup(port,5,1);
	DIO_Connectpullup(port,6,1);
	DIO_Connectpullup(port,7,1);
}


unsigned char Keypad_Read(char port)
{
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'ON','0','=','+'}};
	char row,col,x;
	char return_val = NOTPRESSED;
	for (row = 0;row <=3;row ++)
	{
		DIO_Writepin(port,0,1);
		DIO_Writepin(port,1,1);
		DIO_Writepin(port,2,1);
		DIO_Writepin(port,3,1);
		DIO_Writepin(port,row,0);
		for (col = 0;col <=3;col ++)
		{
			x=DIO_Readpin(port,(col + 4));
			if (x == 0)
			{
				return_val = arr[row][col];
				break;
			}
		}
		if (x == 0)
		{
			break;
		}
	}
	return return_val;
}
