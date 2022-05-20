case idle:
				// Function that take the input from the keypad
			  // Wrong Choice => do while
				// input == A => print "“Popcorn”"
				// if input = b,c,d => state =  user_input
					keypad_getkey();
				  key = keypad_getkey();
				
				if (key == 'A' || key == 'a') {
					m = 1;s = 0;
					LCD_printString("Popcorn");
				
					if (isClosed())
					{
						while (SW2_Input() == 0x1) {};
						state = cooking;
					}
					else {
						LCD_clear();					
						LCD_printString("Door is open !!");
						
						while (!isClosed()) {}
						LCD_clear();
						displayTime(m,s);
						while (SW2_Input() == 0x1) {}
						state = cooking;
					}
				}
				else if (key == 'B'|| key == 'C'||key == 'D') {
					state = user_input;
				}



			
			break;