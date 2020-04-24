#ifndef PROTOCOL_SERIALIZER_H
#define PROTOCOL_SERIALIZER_H
#include "protocol.h"
char* data_unit_serialize(unsigned char request_number,
                          unsigned long sequence_number,
                          char *payload);
data_unit_ptr data_unit_deserialize(char *network_data);
void data_unit_delete(data_unit_ptr du);

#endif
