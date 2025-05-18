/*
 * motor.h
 *
 *  Created on: Oct 8, 2024
 *      Author: lords
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

#define DCMOTOR_INPUT1_PORT_ID    	PORTB_ID
#define DCMOTOR_INPUT1_PIN_ID		PIN0_ID
#define DCMOTOR_INPUT2_PORT_ID		PORTB_ID
#define DCMOTOR_INPUT2_PIN_ID		PIN1_ID
#define DCMOTOR_ENABLE_PORT_ID		PORTB_ID
#define DCMOTOR_ENABLE_PIN_ID		PIN3_ID

/*represents motor state*/
typedef enum
{
	MOTOR_CW, MOTOR_A_CW, MOTOR_stop
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);
#endif /* DC_MOTOR_H_ */
