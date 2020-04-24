#ifndef PROTOCOL_H
#define PROTOCOL_H

/**
 * Constants for tranfering message types
 */
#define DATA_UNIT 1

/**
 * Structure for tranfering data unit
 */
typedef struct _data_unit
{
    unsigned char type : 4;
    unsigned char request_number : 4;
    unsigned long sequence_number;
    char *payload;
} data_unit, *data_unit_ptr;

#define DATA_UNIT_HEADER_LENGTH sizeof(ungined char) + sizeof(unsigned long)
    
#endif
