unsigned char SW3_Input(void)
{
	return (GPIO_PORTA_DATA_R & 0x04);
}