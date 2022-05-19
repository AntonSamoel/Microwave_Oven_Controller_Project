void RGB_Init_on(void)
{
	SYSCTL_RCGCGPIO_R |=0x20;
	while((SYSCTL_PRGPIO_R &0x20)==0);
	
	GPIO_PORTF_LOCK_R = 0x4c4f434b;
	GPIO_PORTF_CR_R |=0xE;
	GPIO_PORTF_PCTL_R &=~0x0000FFF0;
	GPIO_PORTF_AMSEL_R&=~0xE;
	GPIO_PORTF_AFSEL_R &=~0xE;
	GPIO_PORTF_DEN_R |=0xE;
	GPIO_PORTF_DIR_R |=0xE;
	GPIO_PORTF_DATA_R |=0xE;
}


void RGB_Off()
{
	GPIO_PORTF_DATA_R&=~0xE;
}