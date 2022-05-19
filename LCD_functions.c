
void LCD_setcursorRowCol(unsigned int row, unsigned int col)
{
  int command = 0x00;
  if( row == 0)
  {
    command = 0x80;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
    if( row == 1)
  {
    command = 0xC0;
    while(col <=  0x0F && col >= 0x00)
   {
      LCD_command(command + col);
      break;
   
  }
}
	}


void LCD_printInt(int no)
{
	int i=0;
  char toprint[4] = {0};
  sprintf(toprint, "%d", no);
  while(toprint[i] != '\0')
  {
    LCD_data(toprint[i]);
    i++;
  }
}

void LCD_printString(char* str)
{
	int i=0;
  LCD_command(0x0E);
 
  while (str[i] != '\0')
  {
    LCD_data(str[i]);
    i++;
  }
}
int stringtoint(char* key){
	
		int kilo;
		kilo = atoi (key);
	
		return kilo;
	}
