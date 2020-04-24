#include <stdio.h>
#include "../udp_channel.h"

int main(int argc, char *argv[])
{
    printf("Point 2 of channel. Send hello to Point 1.\n");
    udp_channel_ptr channel = udp_channel_init("127.0.0.1",
                                               20010,
                                               "127.0.0.1",
                                               20000,
                                               NULL);
    udp_channel_send(channel, "Hello from Point 2!\n");
    udp_channel_delete(channel);
}
