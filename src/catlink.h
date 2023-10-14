#ifndef CATLINK_H_
#define CATLINK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRUE    1
#define FALSE   0

typedef struct catlink_struct
{
    uint16_t    device_type;        // 2 bytes, start from 0x0000, end to 0xffff.
    uint16_t    device_id;          // 2 bytes, start from 0x0000, end to 0xffff.
    uint8_t     payload_length;     // 1 bytes, also called name 'N'.
    uint16_t    sequence_number;    // 1 bytes, send to other than add by 1.
    uint8_t     payload[244];       // 244 bytes, custom modify area.
} catlink_struct;

extern uint8_t sequence_number;

extern uint8_t * build_packet(catlink_struct);

extern uint8_t unpack_packet(uint8_t *, catlink_struct *);

extern uint16_t calculate_checksum(uint8_t *, uint8_t);

#endif