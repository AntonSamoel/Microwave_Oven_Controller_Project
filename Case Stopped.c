case stopped:
				genericDelay(10);
				RGB_Off();
			genericDelay(10);
				LCD_clear();
			genericDelay(10);
				state = idle;
			m=0, s=0;
			break;