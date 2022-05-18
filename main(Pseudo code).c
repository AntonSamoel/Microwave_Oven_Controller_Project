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
				// input == A => print "�Popcorn�"
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