#ifndef SERVER_H
#define SERVER_H

typedef struct _server
{
    unsigned short port;
} server, *server_ptr;

server_ptr server_init();
void server_run(server_ptr s);
void server_delete(server_ptr s);

#endif
