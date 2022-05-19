void Enter_time(char *x, char *y, char *z ,char *c)
	{
	
	LCD_printString("00:00");	
	LCD_command(0x0C); //display on , cursor off
	//variables to store the input characters from keypad	

	genericDelay(30);
	LCD_setcursorRowCol(0,4);	
	genericDelay(30);
	*x =keypad_getkey();
	LCD_data(*x);		
	genericDelay(30);
	LCD_setcursorRowCol(0,3);	
	genericDelay(30);	
	*y = keypad_getkey();
	LCD_data(*x);	
	LCD_setcursorRowCol(0,4);
	genericDelay(30);	
	LCD_data(*y);	
	LCD_setcursorRowCol(0,3);	
	genericDelay(30);	
	LCD_data(*x);	
	genericDelay(30);	
	*z =keypad_getkey();	
	LCD_setcursorRowCol(0,4);		
	LCD_data(*z);
	genericDelay(30);
	LCD_setcursorRowCol(0,3);
	LCD_data(*y);
	genericDelay(30);	
	LCD_setcursorRowCol(0,1);	
	LCD_data(*x);
	genericDelay(30);	
		
	/*LCD_setcursorRowCol(0,0);
	genericDelay(50);
	LCD_data(x);
	LCD_data(y);
	LCD_data(z);
	LCD_data(c);*/	
	
	LCD_setcursorRowCol(0,4);	
	*c = keypad_getkey();
	genericDelay(30);	
	LCD_data(*c);
	LCD_setcursorRowCol(0,3);
	LCD_data(*z);
	genericDelay(30);
	LCD_setcursorRowCol(0,1);
	LCD_data(*y);
	genericDelay(30);	
	LCD_setcursorRowCol(0,0);
	LCD_data(*x);
	genericDelay(30);	

	//LCD_setcursorRowCol(0,2);	
	//genericDelay(50);
	
	
	
	//*m1= atoi(&x)*10 + atoi(&y);
	//*s1= atoi(&z)*10 + atoi(&c);
}