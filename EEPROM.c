/*
 * EEPROM.c
 *
 * Created: 8/18/2025 11:43:36 PM
 * Author : nanav
 */ 

#include <avr/io.h>
#include "important macros.h"


void EEPROM_Write (unsigned short address ,unsigned char data)
{
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	EEDR = data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}

unsigned char  EEPROM_Read(const unsigned short address)
{
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	SET_BIT(EECR,EERE);
	return EEDR;
}

