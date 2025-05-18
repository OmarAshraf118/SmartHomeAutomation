#include "gpio.h"
#include "ldr.h"
#include "adc.h"

uint16 LDR_getLightIntensity(void)
{
	uint16 lightIntesity_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the LDR sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity from the ADC value*/
	lightIntesity_value = (uint16)(((uint32)adc_value*ADC_REF_VOLT_VALUE*LDR_SENSOR_MAX_LIGHT_INTENSITY)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));
	return lightIntesity_value;
}
