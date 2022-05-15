#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "tm4c123gh6pm.h"

#define idle 0
#define cooking 1
#define paused 2
#define stopped 3
#define user_input 4
#define finished 5


void SWS_Init(void)
{
	SYSCTL_RCGCGPIO_R |=0x20;
	while((SYSCTL_PRGPIO_R &0x20)==0);
	
	GPIO_PORTF_LOCK_R = 0x4c4f434b;
	GPIO_PORTF_CR_R |=0x11;
	GPIO_PORTF_PCTL_R &=~0x000F000F;
	GPIO_PORTF_AMSEL_R&=~0x11;
	GPIO_PORTF_AFSEL_R &=~0x11;
	GPIO_PORTF_PUR_R |=0x11;
	GPIO_PORTF_DEN_R |=0x11;
	GPIO_PORTF_DIR_R &=~0x11;
	
}
void RGB_Init_on(void)
{
	SYSCTL_RCGCGPIO_R |=0x20;
	while((SYSCTL_PRGPIO_R &0x20)==0);
	
	GPIO_PORTF_LOCK_R = 0x4c4f434b;
	GPIO_PORTF_CR_R |=0xE;
	GPIO_PORTF_PCTL_R &=~0x0000FFF0;
	GPIO_PORTF_AMSEL_R&=~0xE;
	GPIO_PORTF_AFSEL_R &=~0xE;
	GPIO_PORTF_DEN_R |=0xE;
	GPIO_PORTF_DIR_R |=0xE;
	GPIO_PORTF_DATA_R |=0xE;
}
// intialize sw3 in PD0
void SW3_Init(void)
{
	SYSCTL_RCGCGPIO_R |=0x8;
	while((SYSCTL_PRGPIO_R &0x8)==0);
	
	//GPIO_PORTF_LOCK_R = 0x4c4f434b;
	GPIO_PORTF_CR_R |=0x11;
	GPIO_PORTF_PCTL_R &=~0x0000000F;
	GPIO_PORTF_AMSEL_R&=~0x01;
	GPIO_PORTF_AFSEL_R &=~0x01;
	GPIO_PORTF_PUR_R |=0x01;
	GPIO_PORTF_DEN_R |=0x01;
	GPIO_PORTF_DIR_R &=~0x01;
}

unsigned char SW1_Input(void)
{
	return (GPIO_PORTF_DATA_R&0x10);
}
	


unsigned char SW3_Input(void)
{
	return (GPIO_PORTD_DATA_R&0x01);
}

unsigned char SW2_Input(void)
{
	return (GPIO_PORTF_DATA_R&0x1);
}

void RGB_Off()
{
	GPIO_PORTF_DATA_R&=~0xE;
	
}


	bool isClosed()
	{
		if(SW3_Input()==0x1) // if Prssed => open
		return true;
		
		else return false;
	}
	// Function to start
	
  void blink_3_times()
	{
		int num;
		for(num=0;num<3;num++)
	{
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		delay(10);
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		delay(100);
	}
	
}
	void blink()
	{
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		delay(10);
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		delay(100);
	}


int main(void)
{
	
	SWS_Init();
	SW3_Init();
	char input = 'D'; // remove d 
	int state = idle;
	
	while(1)
	{
		switch (state){

			// *************************** ideal ***************************
			case idle:
				// Function that take the input from the keypad
			  // Wrong Choice => do while
				// input == A => print "“Popcorn”"
				// if input = b,c,d => state =  user_input
			if(isClosed())
			{
				while(SW2_Input()==0x1){};
				state = cooking;
			}
			
			break;
			
			// *************************** user_input ***************************
			case user_input:
			
			if(input == 'B' )
			{
					// Print Message
				// do while for wrong input !(1=>9)
				while(SW2_Input()==0x1){};
				state = cooking;
				
			}
			else if (input == 'c')
			{
				// Print Message
				// Fumcality
				// do while for wrong input !(1=>9)
				while(SW2_Input()==0x1){};
				state = cooking;
				
			}
			// case D			
			else 
			{
				// Print Message
				// Fumcality
				// do while for wrong input !(1=>30)
				while(SW2_Input()==0x1){};
				state = cooking;
			}
			
			break;
			
			// *************************** cooking ***************************
			case cooking:
			 RGB_Init_on();
			// Timer count down
				if(SW1_Input()!=0x10 || !isClosed())
				{
					// Fucntion that stop the counter
					state = paused;
				}
				//if(//timer finished)
					//state = finished;
			break;

				
			// *************************** paused ***************************
			case paused:
				while(state == paused)
				{
						if(SW1_Input()!=0x10 )// my cause a logical error
						state = stopped;
						else if(SW2_Input()!=0x01 && isClosed())
				{
					// Function remain Cooking
					
					state = cooking;
				}
					blink();
				}
				
			break;
				// *************************** stopped ***************************
			case stopped:
				RGB_Off();
			// Fucntion cleares the time and the cooking stops.
				state = idle;
			break;
			

			// *************************** finished ***************************
			case finished:
				blink_3_times();
			//code for buzzer
				state = idle;
			break;
		}
	
	}
}