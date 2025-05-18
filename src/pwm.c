#include "pwm.h"
#include "gpio.h"
#include <avr/io.h>

/*takes duty cycle as percentage between 0 and 100
 *sets pin OC0 as output
 *sets PWM fast mode, F_1024, and non_inverting mode
 *starts timer at zero*/
void PWM_Timer0_Start(uint8 duty_cycle)
{
	GPIO_setupPinDirection(PWM_OC0_PORT_ID, PWM_OC0_PIN_ID, PIN_OUTPUT);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) |(1<<CS02);

	TCNT0 = 0;
	OCR0 = duty_cycle;



}


