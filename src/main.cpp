extern "C" {
#include "lcd.h"
#include "led.h"
#include "ldr.h"
#include "gpio.h"
#include "buzzer.h"
#include "adc.h"
#include "pwm.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "flame_sensor.h"
#include <util/delay.h>
#include <avr/io.h>
}
typedef enum
{
	FAN_ON, FAN_OFF
}fan_state;

static fan_state g_fanState= FAN_OFF; /*keeps track of fan state*/
static uint8 g_alarmFlag=0; /*keeps track of alarm state*/

/*macro to decide the fan state depending on the current room temperature*/
#define CONTROL_FAN_STATE(CURRENT_TEMP)\
{\
	g_fanState = ((CURRENT_TEMP)<(25) ? (FAN_OFF) : (FAN_ON)); \
}

/* LDR controls LEDs based on light intensity
 * LM35 temperature sensor adjusts the fan speed proportionally to the room temperature
 * A flame sensor detects fire, triggers an alarm, and displays a critical alert on the LCD
 * Shows real-time temperature readings, fan status, light intensity, and alerts*/
void lightControl(void)
{
    if (LDR_getLightIntensity() > 70)
    {
        // If light intensity is high, turn off all LEDs
        LED_off(LED_red);
        LED_off(LED_green);
        LED_off(LED_blue);
    }
    else if (LDR_getLightIntensity() > 50)
    {
        // Turn on the red LED only
        LED_on(LED_red);
        LED_off(LED_green);
        LED_off(LED_blue);
    }
    else if (LDR_getLightIntensity() > 15)
    {
        // Turn on the red and green LEDs
        LED_on(LED_red);
        LED_on(LED_green);
        LED_off(LED_blue);
    }
    else
    {
        // Turn on all LEDs (red, green, and blue)
        LED_on(LED_red);
        LED_on(LED_green);
        LED_on(LED_blue);
    }

}

void fanSpeedControl(void)
{
	uint8 currentTemperature = LM35_getTemperature();
    if (currentTemperature >= 40)
    {
    	DcMotor_Rotate(MOTOR_CW, 100);
    }
    else if (currentTemperature >= 35)
    {
    	DcMotor_Rotate(MOTOR_CW, 75);
    }
    else if (currentTemperature >= 30)
    {
    	DcMotor_Rotate(MOTOR_CW, 50);
    }
    else if(currentTemperature >= 25)
    {
    	DcMotor_Rotate(MOTOR_CW, 25);
    }
    else
    {
    	DcMotor_Rotate(MOTOR_stop, 100);
    }

}


int main(void)
{
	SREG |= (1<<7); /*Enable Global interrupt*/
	ADC_init();
	LCD_init();
	LEDS_init();
	DcMotor_Init();
	FlameSensor_init();
	Buzzer_init();
	LCD_displayStringRowColumn(1, 0,"Temp=   LDR=   %");
    while(1)
    {
    	if(FlameSensor_getValue()) /*if the flame sensor detect flames*/
    	{
    		g_alarmFlag=1;
    		Buzzer_on(); /*turn the buzzer as an alarm*/
    		/*display warning message*/
    		LCD_displayStringRowColumn(0, 0," Critical alert!");
    		LCD_displayStringRowColumn(1, 0,"                ");
    	}
    	else
    	{
    		if(g_alarmFlag) /*if the alarm just closed*/
    		{
    			g_alarmFlag=0;
    			LCD_clearScreen(); /*clear everything from screen*/
    			/*continue to display normal readings data*/
    			LCD_displayStringRowColumn(1, 0,"Temp=   LDR=   %");
    		}
    		Buzzer_off();

    		/*function to control light intensity based on LDR readings*/
    		lightControl();

			CONTROL_FAN_STATE(LM35_getTemperature()) /*macro that sets the fan state depending on temperature readings*/
			if(g_fanState==FAN_ON)
			{
				LCD_displayStringRowColumn(0, 4,"FAN is ON ");
			}
			else
			{
				LCD_displayStringRowColumn(0, 4,"FAN is OFF");
			}

			/*function to control motor speed according to current temperature*/
			fanSpeedControl();

			/*display the current temperature reading on lcd*/
			LCD_moveCursor(1,5);
			LCD_intgerToString((int)LM35_getTemperature());

			LCD_moveCursor(1,12);
			if(LDR_getLightIntensity()>=100)
			{
				LCD_intgerToString((int)LDR_getLightIntensity());
			}
			else
			{
				LCD_intgerToString((int)LDR_getLightIntensity());
				LCD_displayCharacter(' ');
			}
    	}
    }

}
