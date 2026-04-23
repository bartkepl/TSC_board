/*
 * protocol.c
 *
 *  Created on: 23 kwi 2026
 *      Author: bartkepl
 */


#include "protocol.h"
#include "gpio_ctrl.h"

static uint8_t buffer[4];
static uint8_t idx = 0;

static uint8_t device_addr = 0x12;
static uint8_t last_data = 0;
static uint8_t status = 0x01; // OK

extern UART_HandleTypeDef huart1;

uint8_t CRC8(const uint8_t *data, uint8_t len)
{
    uint8_t crc = 0x00;

    for (uint8_t i = 0; i < len; i++)
    {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++)
        {
            crc = (crc & 0x80) ? (crc << 1) ^ 0x07 : (crc << 1);
        }
    }
    return crc;
}

static void send_response(uint8_t data)
{
    TxFrame tx;

    tx.preamble = PREAMBLE;
    tx.addr = device_addr;
    tx.data = data;
    tx.status = status;

    tx.crc = CRC8((uint8_t*)&tx, 4);

    HAL_UART_Transmit(&huart1, (uint8_t*)&tx, 5, 10);
}

static void process_frame()
{
    if (buffer[0] != PREAMBLE) return;

    uint8_t addr = buffer[1];
    uint8_t data = buffer[2];
    uint8_t crc  = buffer[3];

    uint8_t calc[3] = {buffer[0], buffer[1], buffer[2]};

    if (CRC8(calc, 3) != crc)
    {
        status = 0xE1; // CRC error
        return;
    }

    if ((addr & 0x7F) != device_addr)
        return;

    last_data = data;

    GPIOCTRL_Apply(data);

    status = 0x01;

    send_response(data);
}

void PROTOCOL_ProcessByte(uint8_t b)
{
    if (idx == 0 && b != PREAMBLE)
        return;

    buffer[idx++] = b;

    if (idx >= 4)
    {
        process_frame();
        idx = 0;
    }
}

void PROTOCOL_Init(void)
{
    idx = 0;
}
