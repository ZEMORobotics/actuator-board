/*
 * actuator_control.h
 *
 *  Created on: Nov 22, 2026
 *      Author: Vladimir
 */

#ifndef INC_ACTUATOR_CONTROL_H_
#define INC_ACTUATOR_CONTROL_H_

#include "main.h"


/**
  * @brief  Set actuator pin states.
  *
  * @note   This function takes the parameter and based on individual bit values
  *			toggles connected actuators. LSB is the first actuator labeled on
  *			actuator board. 1 - ON, 0 - OFF.
  *
  *			i.e. new_actuator_state = 0x0000000F turns on the first 4 actuators.
  *
  * @param  new_actuator_state - A number where each bit represents 1 actuator connection.
  *
  * @retval None
  */
void set_actuator_state(uint32_t new_actuator_state);

/**
  * @brief  Set all actuator pins to OFF.
  *
  * @retval None
  */
static inline void reset_actuator_state(void) {
	set_actuator_state(0x00000000);
}

#endif /* INC_ACTUATOR_CONTROL_H_ */
