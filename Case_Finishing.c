			case finished:
				
					LCD_clear();			
					genericDelay(50);
				
					buzzer_on();		
					blink_3_times();
					buzzer_off();
					RGB_Off();
					state = idle;
			
			break;