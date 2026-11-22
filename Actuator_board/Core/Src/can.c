/*
 * can.c
 *
 *  Created on: Nov 22, 2026
 *      Author: Vladimir
 */


#include "can.h"

extern FDCAN_HandleTypeDef hfdcan1;
extern volatile uint32_t can_rx_msg;
extern volatile bool new_can_msg;

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) == 0)
        return;

    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t data[8];

    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, data) == HAL_OK) {
    	if (RxHeader.DataLength == FDCAN_DLC_BYTES_4 && RxHeader.RxFrameType == FDCAN_DATA_FRAME) {
    		can_rx_msg = (((uint32_t)data[0]) | ((uint32_t)data[1] << 8) | ((uint32_t)data[2] << 16) | ((uint32_t)data[3] << 24));
    		new_can_msg = true;
    	}
    }


}

void can_init(void) {


    FDCAN_FilterTypeDef f;
    f.IdType       = FDCAN_STANDARD_ID;
    f.FilterIndex  = 0;
    f.FilterType   = FDCAN_FILTER_MASK;
    f.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    f.FilterID1    = 200;
    f.FilterID2    = 0x7FF;

    HAL_FDCAN_ConfigGlobalFilter(
        &hfdcan1,
        FDCAN_REJECT,
        FDCAN_REJECT,
        FDCAN_REJECT_REMOTE,
        FDCAN_REJECT_REMOTE
    );

    HAL_FDCAN_ConfigFilter(&hfdcan1, &f);
    HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
    HAL_FDCAN_Start(&hfdcan1);
}
