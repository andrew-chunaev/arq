#ifndef UDP_CHANNEL_H
#define UDP_CHANNEL_H

#include <netinet/in.h>
#include <sys/socket.h>

typedef struct _upd_channel
{
    struct sockaddr_in src_addr;
    struct sockaddr_in dest_addr;
    int sock;
    void (*on_receive)(char *data, int len);
    char stop_receiving;
} udp_channel, *udp_channel_ptr;

udp_channel_ptr udp_channel_init(char *src_ip_addr, unsigned short src_port, char *dest_ip_addr, unsigned short dest_port, void (*on_receive)(char *data, int len));
void udp_channel_send(udp_channel_ptr channel, const char *data);
void udp_channel_receive(udp_channel_ptr channel);
void udp_channel_delete(udp_channel_ptr channel);
#endif
