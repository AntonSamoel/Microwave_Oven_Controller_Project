unsigned char SW1_Input(void)
{
	return (GPIO_PORTF_DATA_R&0x10);
}

unsigned char SW2_Input(void)
{
	return (GPIO_PORTF_DATA_R&0x01);
}