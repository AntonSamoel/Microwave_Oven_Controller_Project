#include "C:\Keil 4\Labware\tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delay.h"

//port 'A' for control(RS,R\W,E) pin 5,6,7
//
//
//port 'B' for data all pins

void LCD_command (unsigned char command);


void LCD_init (void){
	
	
	SYSCTL_RCGCGPIO_R |=0x03;                      // Enable clock for ports


	while ((SYSCTL_PRGPIO_R & 0x03)==0){};  //wait til ports are activated
	
		GPIO_PORTA_CR_R  |= 0xE0;          // allow changes to all the bits in port A
	GPIO_PORTA_DIR_R |= 0xE0;          // set PORTA pin 7-5 as output for control
	GPIO_PORTA_DEN_R |= 0xE0;          // set PORTA pin 7-5 as digital pins 
	GPIO_PORTB_CR_R  |= 0xFF;          // allow changes to all the bits in port B
	GPIO_PORTB_DEN_R |= 0XFF;
	GPIO_PORTB_DIR_R |= 0XFF;
	genericDelay (20);
	LCD_command(0x38); //8-bits,2 display lines, 5x7 font
	genericDelay(5);
	LCD_command(0x08);
	LCD_command(0x01); //clear display
	LCD_command(0x06); //increments automatically to right
	LCD_command(0x0F); //Turn on display

}


void LCD_clear(void){         //lcd clearing
LCD_command(0x01);
}



void LCD_command (unsigned char command){

	GPIO_PORTA_DATA_R &=~0x00; // RS,E,R\w = 0
	GPIO_PORTB_DATA_R =command;
	GPIO_PORTA_DATA_R =0x80; //E =1
	systick_10MicroSec(0.1);
	GPIO_PORTA_DATA_R = 0x00;           //High to Low pulse to push the command to the LCD
	if(command <4) genericDelay(2);
else systick_10MicroSec(4); 
	
	
} 

	
void LCD_data (unsigned char data){
	GPIO_PORTA_DATA_R =0x20; // RS =1  E=0  R\W=0
	GPIO_PORTB_DATA_R= data;
	
	
	  GPIO_PORTA_DATA_R = 0x80 | 0x20;
  systick_10MicroSec(0.1);
  GPIO_PORTA_DATA_R = 0;          //High to Low pulse to push the data to the LCD
  systick_10MicroSec(4);
	GPIO_PORTB_DATA_R =0x00;

}
