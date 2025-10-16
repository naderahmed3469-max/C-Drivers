/*
 * ADC.c
 *
 * Created: 9/4/2025 4:28:27 PM
 * Author : nanav
 */ 

#include <avr/io.h>
#include "important macros.h"



void ADC_Init(void)
{
	SET_BIT(ADMUX,REFS0); // config VREF
	SET_BIT(ADCSRA,ADEN); // enable ADC
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}


unsigned short ADC_Read(void)
{
	unsigned short read_val;
	
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA,ADIF);
	read_val =(ADCL);
	read_val |= (ADCH<<8);
	return read_val; 
}