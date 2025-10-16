/*
 * 7SEG Driver.c
 *
 * Created: 8/10/2025 12:08:30 AM
 * Author : nanav
 */ 

#include <avr/io.h>
#include "DIO.h"
#define common_mode 1			//1 for common cathode 0 for common anode 


void Seven_seg_init(char port)
{
	
	DIO_Setportdir(port,0xFF); 
}

#if common_mode

void Seven_seg_write(char port,char val)
{
	char arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	DIO_Writeport(port,arr[val]);
	
}

#else 
void Seven_seg_write(char port,char val)
{
	char arr[] = {~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
	DIO_Writeport(port,arr[val]);
	
}
#endif