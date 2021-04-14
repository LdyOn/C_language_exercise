#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>

#define  HOST_NAME_MAX 256



int
main()
{
    int n;
    char *host;

    if(( n = sysconf(_SC_HOST_NAME_MAX)) <0 ){
        n = HOST_NAME_MAX;
    }

    if((host = malloc(n))==NULL)
        printf("malloc error");
    if( gethostname(host,n)<0 )
        printf("malloc error");
    printf("host: %s", host);
    exit(0);
}