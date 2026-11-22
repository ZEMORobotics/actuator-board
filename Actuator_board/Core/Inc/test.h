/*
 * test.h
 *
 *  Created on: Nov 22, 2026
 *      Author: Vladimir
 */

#ifndef INC_TEST_H_
#define INC_TEST_H_

#include "main.h"
#include "actuator_control.h"

/**
 * @brief Turn On every single actuator pin one by one.
 *
 */
void test1(void);

/**
 * @brief Turn On multiple actuator pins at the time.
 *
 */
void test2(void);

/**
 * @brief Turn On all actuator pins.
 *
 */
void test3(void);


#endif /* INC_TEST_H_ */
