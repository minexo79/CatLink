#include "catlink.h"

uint8_t * build_packet(catlink_struct src)
{
    uint8_t * ret = (uint8_t *)calloc(255, sizeof(uint8_t));

    // Header => CATI
    ret[0] = 'C';
    ret[1] = 'A';
    ret[2] = 'T';
    ret[3] = 'I';

    // device type
    ret[4] = src.device_type >> 8;
    ret[5] = src.device_type;

    // device id
    ret[6] = src.device_id >> 8;
    ret[7] = src.device_id;

    // payload length
    ret[8] = src.payload_length;

    // sequence number
    ret[9] = (src.sequence_number == 255) ? 0 : src.sequence_number + 1;

    // payload
    for(int i = 0; i < src.payload_length; i++)
        ret[10 + i] = src.payload[i];
    
    // checksum
    uint16_t checksum = calculate_checksum(ret, src.payload_length);
    ret[254] = checksum >> 8;
    ret[255] = checksum;

    return ret;
}

uint8_t unpack_packet(uint8_t * src, catlink_struct * ret)
{
    // identify header and checksum
    if (src[0] == 'C' && src[1] == 'A' && src[2] == 'T' && src[3] == 'I')
    {
        uint16_t checksum = calculate_checksum(src, src[8]);
        if ((((uint16_t)src[254]) << 8) + src[255] == checksum)
        {
            // device type
            ret->device_type = (((uint16_t)src[4]) << 8) + src[5];
            
            // device id
            ret->device_id = (((uint16_t)src[6]) << 8) + src[7];

            // payload length
            ret->payload_length = src[8];

            // sequence number
            ret->sequence_number = src[9];

            // payload
            for(int i = 0; i < ret->payload_length; i++)
                ret->payload[i] = src[10 + i];

            return TRUE;
        }
    }

    return FALSE;
}

uint16_t calculate_checksum(uint8_t * src, uint8_t length)
{
    uint16_t ret = 0;

    for(uint8_t i = 0; i < 10 + length; i++)    // 0 ~ 10 + payload length
        ret += src[i];

    return ret;
}