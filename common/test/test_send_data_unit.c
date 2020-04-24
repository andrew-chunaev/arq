#include <stdio.h>
#include "../udp_channel.h"
#include "../protocol.h"
#include "../protocol_serializer.h"

int main(int argc, char *argv[])
{
    unsigned char request_number;
    unsigned long sequence_number;
    char message[1024];
    printf("request_number: ");
    scanf("%d", &request_number);
    printf("\n");
    printf("sequence_number: ");
    scanf("%d", &sequence_number);
    printf("\n");
    printf("message: ");
    scanf("%s", message);
    printf("\n");
    udp_channel_ptr channel = udp_channel_init("127.0.0.1",
                                               20010,
                                               "127.0.0.1",
                                               20000,
                                               NULL);
    udp_channel_send(channel, data_unit_serialize(request_number,
                                                  sequence_number,
                                                  message));
    udp_channel_delete(channel);
}
