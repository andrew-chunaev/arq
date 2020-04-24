#include "udp_channel.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#define MAX_BUF_LENGTH 1500

udp_channel_ptr udp_channel_init(char *src_ip_addr, unsigned short src_port, char *dest_ip_addr, unsigned short dest_port, void (*on_receive)(char *data, int len))
{
    udp_channel_ptr channel = malloc(sizeof(udp_channel));
    channel->sock = socket(AF_INET, SOCK_DGRAM, 0);
    
    channel->src_addr.sin_family = AF_INET;
    inet_pton(AF_INET, src_ip_addr, &channel->src_addr.sin_addr);
    channel->src_addr.sin_port = htons(src_port);

    bind(channel->sock, (struct sockaddr *) &channel->src_addr, sizeof(channel->src_addr));
    
    channel->dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, dest_ip_addr, &channel->dest_addr.sin_addr);
    channel->dest_addr.sin_port = htons(dest_port);    
    
    channel->on_receive = on_receive;
    channel->stop_receiving = 1;    
}

void udp_channel_send(udp_channel_ptr channel, const char *data)
{
    sendto(channel->sock, data, strlen(data), 0,
           (const struct sockaddr *) &channel->dest_addr, sizeof(channel->dest_addr)); 
}


void* receive_loop(void *args)
{
    udp_channel_ptr channel = (udp_channel_ptr) args;
    char receive_buffer[MAX_BUF_LENGTH];
    int recv_len;
    int slen;
    struct sockaddr_in si_from;
    while(!channel->stop_receiving)
    {         
        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(channel->sock, receive_buffer, MAX_BUF_LENGTH, 0, (struct sockaddr *) &si_from, &slen)) == -1)
        {
            perror("recvfrom()");
            exit(EXIT_FAILURE);
        }
        else
        {
            if (recv_len)
            {    
                channel->on_receive(receive_buffer, recv_len);
            }
        }
         
    }
    printf("Receiving stopped\n");
    return NULL;
}

void udp_channel_receive(udp_channel_ptr channel)
{
    channel->stop_receiving = 0;
    pthread_t receiving_thread;
    pthread_create(&receiving_thread, NULL, receive_loop, (void *) channel);
}

void udp_channel_delete(udp_channel_ptr channel)
{
    channel->stop_receiving  = 1;
    shutdown(channel->sock, SHUT_RD);
    close(channel->sock);
    free(channel);
}
