#include <stdio.h>

#include "../udp_channel.h"
#include "../protocol.h"
#include "../protocol_serializer.h"

void test_receive(char *data, int len)
{
    data_unit_ptr du = data_unit_deserialize(data);
    printf("-----------------------------------------------------------\n");
    printf("|type: %02d| request_number: %02d| sequence_number: %010d|\n", du->type, du->request_number, du->sequence_number);
    printf("-----------------------------------------------------------\n");
    printf("%s\n", du->payload);
    data_unit_delete(du);
}

int main(int argc, char *argv[])
{
    printf("Waiting for message...\n");
    udp_channel_ptr channel = udp_channel_init("127.0.0.1",
                                               20000,
                                               "127.0.0.1",
                                               20010,
                                               test_receive);
    udp_channel_receive(channel);
    sleep(30);
    udp_channel_delete(channel);
    sleep(10);
    
}
