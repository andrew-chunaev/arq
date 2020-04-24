#include "stdio.h"
#include "server.h"
int main(int argc, char *argv[])
{
    printf("      ******************\n");
    printf("      *   ARQ server   *\n");
    printf("      ******************\n");
    
    server_ptr s = server_init();
    server_run(s);
    server_delete(s);
}
