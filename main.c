#include "LPC11XX.H"
uint8_t table[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	
void delay()
{
	uint16_t i=4000;
	while(i--);
}
void GPIOInit(void)
{
	LPC_GPIO2 ->DIR |= 0xFF;				//??P2_0~P2_7???
	
}
void Display(uint32_t value)
{
	LPC_GPIO2->DATA &= ~(1<<8);
	LPC_GPIO2->DATA	= table[value/1000];	
	delay();
	LPC_GPIO2->DATA |= (1<<8);
	LPC_GPIO2->DATA = 0xFF;
	LPC_GPIO2->DATA &= ~(1<<9);
	LPC_GPIO2->DATA	= table[value%1000/100];	
	delay();
	LPC_GPIO2->DATA |= (1<<9);
	LPC_GPIO2->DATA = 0xFF;
	
	LPC_GPIO2->DATA &= ~(1<<10);
	LPC_GPIO2->DATA = table[value%1000%100/10];	
	delay();
	LPC_GPIO2->DATA |= (1<<10);
	LPC_GPIO2->DATA = 0xFF;
	LPC_GPIO2->DATA &= ~(1<<11);
	LPC_GPIO2->DATA = table[value%1000%1000%10];	
	delay();
	LPC_GPIO2->DATA |= (1<<11);
	LPC_GPIO2->DATA = 0xFF;   
}
	
int main()
{
	GPIOInit();
	while(1)
	{
		Display(9876);
	}
}