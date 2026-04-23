/*
 * gpio_ctrl.c
 *
 *  Created on: 23 kwi 2026
 *      Author: bartkepl
 */


#include "gpio_ctrl.h"

static uint8_t g_channels = 0;

extern ChannelGPIO ch_map[4]; // zdefiniowane w main.c

void GPIOCTRL_Init(uint8_t channels)
{
    g_channels = channels;

    // wszystko OFF
    for (uint8_t i = 0; i < g_channels; i++) {
        GPIOCTRL_SetChannel(i, 0);
    }
}

static void set_off(ChannelGPIO *ch)
{
    HAL_GPIO_WritePin(ch->r1_port, ch->r1_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ch->r2_port, ch->r2_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ch->r3_port, ch->r3_pin, GPIO_PIN_SET);
}

void GPIOCTRL_SetChannel(uint8_t ch, uint8_t mode)
{
    if (ch >= g_channels) return;

    ChannelGPIO *c = &ch_map[ch];

    set_off(c);

    switch(mode)
    {
        case 1: HAL_GPIO_WritePin(c->r1_port, c->r1_pin, GPIO_PIN_RESET); break;
        case 2: HAL_GPIO_WritePin(c->r2_port, c->r2_pin, GPIO_PIN_RESET); break;
        case 3: HAL_GPIO_WritePin(c->r3_port, c->r3_pin, GPIO_PIN_RESET); break;
        default: break;
    }
}

void GPIOCTRL_Apply(uint8_t data4x2)
{
    for (uint8_t ch = 0; ch < g_channels; ch++)
    {
        uint8_t mode = (data4x2 >> (ch * 2)) & 0x03;
        GPIOCTRL_SetChannel(ch, mode);
    }
}
