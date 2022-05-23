
  void blink_3_times()
	{
		int num;
		for(num=0;num<3;num++)
	{
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		genericDelay(1000);
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		genericDelay(100);
	}
	
}
	void blink()
	{
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		genericDelay(250);
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ 0x0E;
		genericDelay(250);
	}
		
