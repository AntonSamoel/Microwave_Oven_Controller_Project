#include "lcd.h"
void displayTime(int m,int s)
{
  LCD_command(0x01);
 
  if(m>9){
	 
	LCD_setcursorRowCol(0, 5);
  LCD_printInt(m);
	}
	else{
				LCD_setcursorRowCol(0, 5);
				LCD_printInt(0);
				LCD_setcursorRowCol(0, 6);
				LCD_printInt(m);
	}
  LCD_setcursorRowCol(0, 7);
  LCD_data(':');
  if (s>9){LCD_setcursorRowCol(0, 8);
  LCD_printInt(s);
	}
	else{
		{LCD_setcursorRowCol(0, 8);
			
			LCD_printInt(0);
			LCD_setcursorRowCol(0, 9);
			LCD_printInt(s);
	}
		
}
}
