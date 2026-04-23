/*
 * protocol.h
 *
 *  Created on: 23 kwi 2026
 *      Author: bartkepl
 */

#ifndef INC_PROTOCOL_H_
#define INC_PROTOCOL_H_

#include <stdint.h>

#define PREAMBLE 0xAA

typedef struct {
    uint8_t preamble;
    uint8_t addr;
    uint8_t data;
    uint8_t crc;
} RxFrame;

typedef struct {
    uint8_t preamble;
    uint8_t addr;
    uint8_t data;
    uint8_t status;
    uint8_t crc;
} TxFrame;

uint8_t CRC8(const uint8_t *data, uint8_t len);

void PROTOCOL_ProcessByte(uint8_t b);
void PROTOCOL_Init(void);

#endif /* INC_PROTOCOL_H_ */
