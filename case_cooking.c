case cooking:
			 RGB_Init_on();
				f=false;
			 while(m >= 0)
			 {
				 while(s >= 0)
				 {
					  LCD_clear();
					 //LCD_init();
					 
						displayTime(m ,s);

						genericDelay(1000);              
						s--;         
						if(m==0 && s==0){
							state = finished;
							genericDelay(1);
						}
						if(SW1_Input() != 0x10 || !isClosed()){
							genericDelay(1);
							state = paused;
							f=true;
							break;
						}
						
				}
				 if(f){
				 break;}
				m--;
				s = 59;      
		}

			 
			break;
