#include "C:\Keil 4\Labware\tm4c123gh6pm.h"

void SysTick_Done(unsigned long delay){ 
			NVIC_ST_CTRL_R = 0; 
			NVIC_ST_RELOAD_R = delay - 1; 
			NVIC_ST_CURRENT_R = 0; 
			NVIC_ST_CTRL_R = 0x05; 
 while((NVIC_ST_CTRL_R & 0x00010000)==0){} 
} 

void genericDelay(unsigned long delay){   //1 ms delay
int i; 
 for(i=0;i<delay;i++){ 
 SysTick_Done(80000);
 }
}



void systick_10MicroSec( double delay){
	unsigned long i;
	for(i=0 ;i<delay ; i++){
	SysTick_Done(800);

	}
}