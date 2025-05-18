#include "led.h"
#include "gpio.h"

/*initialize led port and pin*/
 void LEDS_init(void)
{
	 /*Initializes all LEDs*/
	GPIO_setupPinDirection(LED_PORT_ID, LED_red, PIN_OUTPUT); /*set pin direction*/
	GPIO_setupPinDirection(LED_PORT_ID, LED_green, PIN_OUTPUT); /*set pin direction*/
	GPIO_setupPinDirection(LED_PORT_ID, LED_blue, PIN_OUTPUT); /*set pin direction*/
	/*Turn all LEDs off*/
	GPIO_writePin(LED_PORT_ID, LED_red, LED_OFF); /*turn led off*/
	GPIO_writePin(LED_PORT_ID, LED_green, LED_OFF); /*turn led off*/
	GPIO_writePin(LED_PORT_ID, LED_blue, LED_OFF); /*turn led off*/
}

 void LED_on(LED_ID id)
{
	GPIO_writePin(LED_PORT_ID, id, LED_ON); /*turn led on*/
}

 void LED_off(LED_ID id)
{
	GPIO_writePin(LED_PORT_ID, id, LED_OFF); /*turn led off*/
}

