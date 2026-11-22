/*
 * test.c
 *
 *  Created on: Nov 22, 2026
 *      Author: Vladimir
 */

#include "test.h"


void test1(void) {
	uint32_t state = 0x00000001;

	for (int i = 0; i < 32; i++) {
		set_actuator_state(state);
		state = state << 1;
		HAL_Delay(500);
	}

	reset_actuator_state();
}


void test2(void) {
	uint32_t state = 0x0000000F;

	for (int i = 0; i < 8; i++) {
		set_actuator_state(state);
		state = state << 4;
		HAL_Delay(500);
	}

	reset_actuator_state();
}


void test3(void) {
	// kavabanga
	uint32_t state = 0xFFFFFFFF;
	set_actuator_state(state);
	HAL_Delay(2000);
	reset_actuator_state();
}
