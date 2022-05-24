		case user_input:
			
				if (key == 'B')
				{

					do {
						LCD_printString("Beef weight?");
						genericDelay(500);
							
						 k = keypad_getkey();						
							genericDelay(50);	
							LCD_clear();
							kilos = stringtoint(&k);		
							LCD_printInt(kilos);
							genericDelay(1000);	
							LCD_clear();
						
						if (kilos % 2 == 0) {
							m = kilos * 0.5;
							s = 0;
						}
						else {
							m = kilos * 0.5;
							s = 30;
						}
						if (!(kilos >= 1 && kilos <= 9)) {
							LCD_clear();
							genericDelay(5);
							LCD_printString("ERR!");
							genericDelay(2000);
						}

					} while (!(kilos >= 1 && kilos <= 9));

					if (isClosed())
					{
						displayTime(m,s);
						while (SW2_Input() == 0x1) {}
						state = cooking;
					}
					else {
						LCD_clear();
						LCD_printString("Door is open !!");
						while (!isClosed()){}
						LCD_clear();
						displayTime(m,s);
						while (SW2_Input() == 0x1) {}
						state = cooking;
					}
				
			}
			else if (key == 'C')
			{
					do {
						LCD_printString("chiken weight?");
						genericDelay(500);
						 k = keypad_getkey();					
						genericDelay(50);
						LCD_clear();
						 kilos = stringtoint(&k);	
						LCD_printInt(kilos);
						genericDelay(1000);							
						LCD_clear();
						if (kilos % 5 == 0) {
							m = kilos * (0.2);
							s = 0;
						}
						else {
							total = kilos * 12;
							m = total/60;
							s = total % 60;
						}
						if (!(kilos >= 1 && kilos <= 9)) {
							LCD_clear();
							genericDelay(5);
							LCD_printString("ERR!");
							genericDelay(2000);
						}

					} while (!(kilos >= 1 && kilos <= 9));

					if (isClosed())
					{	
						displayTime(m,s);
						while (SW2_Input() == 0x1) {}
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
			 else if (key == 'D'){
			LCD_printString("Cooking Time ?");
				 
			genericDelay(1000);
			LCD_clear();
			Enter_time(&x, &y, &z, &c);	
			genericDelay(2500);

			if (isClosed())
					{
						m = atoi(&x)*10 + atoi(&y);			
						s= atoi(&z)*10 + atoi(&c) ;
						LCD_clear();
						displayTime(m, s);
						while (SW2_Input() == 0x1) {}
						state = cooking;
					}
					else {
						
						LCD_clear();
						LCD_printString("Door is open !!");
						while (!isClosed()) {}
						LCD_clear();						
						m = atoi(&x)*10 + atoi(&y);			
						s= atoi(&z)*10 + atoi(&c) ;
					  displayTime(m,s);
						while (SW2_Input() == 0x1) {}
						state = cooking;
					}
			
			break;
			
