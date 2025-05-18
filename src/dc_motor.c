#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"
#include <util/delay.h>

void DcMotor_Init(void)
 {
	/*Initialize motor pins*/
	GPIO_setupPinDirection(DCMOTOR_INPUT1_PORT_ID, DCMOTOR_INPUT1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_INPUT2_PORT_ID, DCMOTOR_INPUT2_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_ENABLE_PORT_ID, DCMOTOR_ENABLE_PIN_ID, PIN_OUTPUT);
	/*stop the motor at the beginning*/
	GPIO_writePin(DCMOTOR_INPUT1_PORT_ID, DCMOTOR_INPUT1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DCMOTOR_INPUT2_PORT_ID, DCMOTOR_INPUT2_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DCMOTOR_ENABLE_PORT_ID, DCMOTOR_ENABLE_PIN_ID, LOGIC_LOW);
 }

void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	if(state == MOTOR_CW)
	{
		GPIO_writePin(DCMOTOR_INPUT1_PORT_ID, DCMOTOR_INPUT1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DCMOTOR_INPUT2_PORT_ID, DCMOTOR_INPUT2_PIN_ID, LOGIC_LOW);
	}
	else if(state == MOTOR_A_CW)
	{
		GPIO_writePin(DCMOTOR_INPUT1_PORT_ID, DCMOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DCMOTOR_INPUT2_PORT_ID, DCMOTOR_INPUT2_PIN_ID, LOGIC_HIGH);
	}
	else if(state == MOTOR_stop)
	{
		GPIO_writePin(DCMOTOR_INPUT1_PORT_ID, DCMOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DCMOTOR_INPUT2_PORT_ID, DCMOTOR_INPUT2_PIN_ID, LOGIC_LOW);
	}
	/*change the speed to a value corresponding to the speed percentage*/
	uint8 pwm_value = (uint8)((speed * 255) / 100);
	PWM_Timer0_Start(pwm_value);
}
