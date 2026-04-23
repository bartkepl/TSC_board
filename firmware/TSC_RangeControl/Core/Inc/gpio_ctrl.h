/*
 * gpio_ctrl.h
 *
 *  Created on: 23 kwi 2026
 *      Author: bartkepl
 */

#ifndef INC_GPIO_CTRL_H_
#define INC_GPIO_CTRL_H_

#include "stm32c0xx_hal.h"
#include <stdint.h>

#define MAX_CHANNELS 4

typedef struct {
    GPIO_TypeDef* r1_port;
    uint16_t r1_pin;
    GPIO_TypeDef* r2_port;
    uint16_t r2_pin;
    GPIO_TypeDef* r3_port;
    uint16_t r3_pin;
} ChannelGPIO;

void GPIOCTRL_Init(uint8_t channels);
void GPIOCTRL_SetChannel(uint8_t ch, uint8_t mode);
void GPIOCTRL_Apply(uint8_t data4x2);

#endif /* INC_GPIO_CTRL_H_ */
