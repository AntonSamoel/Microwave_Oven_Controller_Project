	void SW3_Buzzer_Init(void)
{
    SYSCTL_RCGCGPIO_R |=0x1;
    while((SYSCTL_PRGPIO_R &0x1)==0);


    GPIO_PORTA_CR_R |=0xc;
    GPIO_PORTA_PCTL_R &=~0x0000FF00;
    GPIO_PORTA_AMSEL_R&=~0xc;
    GPIO_PORTA_AFSEL_R &=~0xc;
		GPIO_PORTA_PUR_R |=0x4;
    GPIO_PORTA_DEN_R |=0xc;
    GPIO_PORTA_DIR_R |=0x8;
		GPIO_PORTA_DIR_R &=~0x4;

}