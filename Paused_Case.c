			// *************************** paused ***************************
			case paused:
				while (1)
				{
					blink();
					genericDelay(10);
					if (SW1_Input() != 0x10){
						genericDelay(1);												
						state = stopped;
						
						break;
					}
					
					else if (SW2_Input() != 0x01 && isClosed()) {
						genericDelay(1);
						state = cooking;
						break;
					}
					
				}
					// Function remain Cooking
					
			
			break;