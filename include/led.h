#ifndef LED_H_
#define LED_H_

/************************************************************************************************************
 * Includes
 *************************************************************************************************************/
#include "std_types.h"


/************************************************************************************************************
 * Type Definition
 ************************************************************************************************************/
/*if led is connected using negative logic
 *define NEGATIVE_LOGIC*/
#ifdef NEGATIVE_LOGIC
typedef enum
{
	LED_ON, LED_OFF
}LED_state;
#else
typedef enum
{
	LED_OFF, LED_ON
}LED_state;
#endif
#define LED_PORT_ID			PORTB_ID


typedef enum
{
	LED_red=5, LED_green, LED_blue
}LED_ID;
/************************************************************************************************************
 * Function Prototype
 ************************************************************************************************************/

/*initialize led port and pin*/
void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif /*LED_H_*/
