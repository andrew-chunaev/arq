#include "protocol_serilizer.h"

char* data_unit_serialize(unsigned char request_number,
                          unsigned long sequence_number,
                          char *payload)
{
    int payload_len = sizeof(payload);
    data_unit du;
    du.type = DATA_UNIT;
    du.request_number = request_number;
    du.sequence_number = sequence_number; 
    char* network_data = malloc(payload_len + DATA_UNIT_HEADER_LENGTH);
    memcpy(network_data, du, DATA_UNIT_HEADER_LENGTH);
    memcpy(&network_data[DATA_UNIT_HEADER_LENGTH], payload, payload_len);
    return network_data;
}
    
data_unit_ptr data_unit_deserialize(char *network_data)
{
    data_unit_ptr du = malloc(sizeof(data_unit));
    *du = (data_unit) network_data;
    int payload_len = sizeof(nework_data) - DATA_UNIT_HEADER_LENGTH;
    du->payload = malloc(payload_len);
    memcpy(du->payload, newtork_data[DATA_UNIT_HEADER_LENGTH, payload_len);
    return du;
}

void data_unit_delete(data_unit_ptr du)
{
    delete du->payload;
    delete du;
}
