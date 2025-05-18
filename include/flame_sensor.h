/*
 * flame_sensor.h
 *
 *  Created on: Oct 8, 2024
 *      Author: lords
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

#define FLAMESENSOR_PORT_ID 		PORTD_ID
#define FLAMESENSOR_PIN_ID  		PIN2_ID

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
