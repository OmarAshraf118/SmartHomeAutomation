#include "flame_sensor.h"
#include "gpio.h"

void FlameSensor_init(void)
{
	/*Initializes the flame sensor pin direction.*/
	GPIO_setupPinDirection(FLAMESENSOR_PORT_ID, FLAMESENSOR_PIN_ID, PIN_INPUT);
}

uint8 FlameSensor_getValue(void)
{
	/*Reads the value from the flame sensor and returns it*/
	return GPIO_readPin(FLAMESENSOR_PORT_ID, FLAMESENSOR_PIN_ID);
}
