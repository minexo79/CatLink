/**
 * CatLink Test 01
 * Just Test Packet And Unpack Method Are Working Properly.
 * ========================================================
 * Version: 0.1
 * Date:    2023.10.15
 * Author:  blackcat
 */

#include <stdio.h>
#include <stdlib.h>
#include "catlink.h"

int main(void)
{
    catlink_struct struct1 = {
        .device_type = 0x0001,
        .device_id = 0x0001,
        .payload_length = 5,
        .sequence_number = 0,
        .payload = "HELLO"
    };

    printf("Packet...\t");
    uint8_t * test_pack = build_packet(struct1);
    printf("Successfully!!!\n");

    catlink_struct test_unpack = {};

    printf("Unpack...\t");
    if (unpack_packet(test_pack, &test_unpack) == TRUE)
    {
        printf("Successfully!!!\n===============\n");
        printf("Device Type:\t%d\nDevice ID:\t%d\nPayload Length:\t%d\nSeq Number:\t%d\nPayload:\t%s\n", 
            test_unpack.device_type, 
            test_unpack.device_id, 
            test_unpack.payload_length,
            test_unpack.sequence_number,
            test_unpack.payload);
    }
    else
        printf("Error!!!\n");

    return 0;
}