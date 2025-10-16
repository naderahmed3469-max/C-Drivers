/*
 * LCD.h
 *
 * Created: 8/24/2025 9:45:36 PM
 *  Author: nanav
 */ 


#ifndef LCD_H_
#define LCD_H_
#define  CLR_Screen 0x01
#define Return_Home 0x02
#define LCD_Dataport 'A'
#define LCD_Controlport 'B'
#define EN 0
#define Rs 1
#define RW 2
#define Mode 0                      //1 -> 8-bit mode   0-> 4-bit mode//
// Main Commands
#define CLR_SCREEN           0x01
#define RETURN_HOME          0x02
#define FIRST_LINE           0x80
#define SECOND_LINE          0xC0

// Entry mode set
#define ENTRY_MODE            0x06  // Increment, no shift
#define ENTRY_MODE_RTL        0x04  // Decrement, no shift
#define ENTRY_MODE_INC_SHIFT  0x07
#define ENTRY_MODE_DEC_SHIFT  0x05

// Display Control Commands
#define DISPLAY_OFF               0x08  // display off, cursor off, blink off
#define DISPLAY_ON_CURSOR_OFF     0x0C  // display on, cursor off, blink off
#define CURSOR_OFF_BLINK_ON       0x0D  // display on, cursor off, blink on
#define CURSOR_ON_BLINK_OFF       0x0E  // display on, cursor on, blink off
#define CURSOR_ON_BLINK_ON        0x0F  // display on, cursor on, blink on

// Cursor or Display Shift
#define SHIFT_CURSOR_LEFT         0x10
#define SHIFT_CURSOR_RIGHT        0x14
#define SHIFT_DISPLAY_LEFT        0x18
#define SHIFT_DISPLAY_RIGHT       0x1C

// Function Set Variants
#define FUNCTION_SET_4BIT_1LINE   0x20
#define FUNCTION_SET_8BIT_1LINE   0x30

#define FUNCTION_SET_4BIT_2LINE   0x28
#define FUNCTION_SET_8BIT_2LINE   0x38







static void enable(void);
void LCD_Sendchar(char data);
void LCD_Sendcmd(char cmd);
void LCD_Clear_Screen(void);
void LCD_Init(void);
void LCD_Sendstring(char *ptr);
void LCD_movecursor(char row,char col);




#endif /* LCD_H_ */