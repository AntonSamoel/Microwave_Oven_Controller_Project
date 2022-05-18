void buzzer_on(void)
{
    GPIO_PORTA_DATA_R |= 0x08;
}
void buzzer_off()
{
    GPIO_PORTA_DATA_R &= ~0x08;
}