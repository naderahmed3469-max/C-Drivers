/*
 * EEPROM.h
 *
 * Created: 8/19/2025 12:00:48 AM
 *  Author: nanav
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_Write (unsigned short address ,unsigned char data);
unsigned char  EEPROM_Read(const unsigned short address);




#endif /* EEPROM_H_ */