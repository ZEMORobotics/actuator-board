/*
 * actuator_control.c
 *
 *  Created on: Nov 22, 2026
 *      Author: Vladimir
 */

#include "actuator_control.h"


void set_actuator_state(uint32_t new_actuator_state) {
	const uint32_t mask = 0x80000000;
	uint32_t current_serial_state = 0;

	for (int i = 0; i < 32; ++i) {
		current_serial_state = 0;

		if ((new_actuator_state & mask) != 0) {
			current_serial_state = 1;
		}

		new_actuator_state = new_actuator_state << 1;

		HAL_GPIO_WritePin(serial_data_GPIO_Port, serial_data_Pin, current_serial_state);
		delay_us(1);
		HAL_GPIO_WritePin(serial_clock_GPIO_Port, serial_clock_Pin, GPIO_PIN_SET);
		delay_us(1);
		HAL_GPIO_WritePin(serial_clock_GPIO_Port, serial_clock_Pin, GPIO_PIN_RESET);

	}

	HAL_GPIO_WritePin(latch_GPIO_Port, latch_Pin, GPIO_PIN_SET);
	delay_us(1);
	HAL_GPIO_WritePin(latch_GPIO_Port, latch_Pin, GPIO_PIN_RESET);
}
