#include <stdlib.h>
#include "server.h"

server_ptr server_init()
{
    return NULL;
}
void server_run(server_ptr s)
{
    
}
void server_delete(server_ptr s)
{
    free(s);
}
