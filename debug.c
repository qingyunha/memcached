#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/signal.h>
#include <sys/resource.h>
#include <sys/uio.h>

#include <pwd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>
#include <event.h>
#include <assert.h>
#include <limits.h>

#include "memcached.h"

void print_conn(conn *c){

    fprintf(stderr, "buffer to read commands into: ");
    fprintf(stderr, " \"%s\"  cur_pos:%ld  total_size:%d, unparsed_size:%d\n", c->rbuf, c->rcurr-c->rbuf, c->rsize, c->rbytes);

    fprintf(stderr, "buffer to write: ");
    fprintf(stderr, " \"%s\"  cur_pos:%ld  total_size:%d, write_size:%d\n", c->wbuf, c->wcurr-c->wbuf, c->wsize, c->wbytes);

}

void print_msg_info(conn *c) {

    fprintf(stderr, "iovsize:%d  iovused:%d\n", c->iovsize, c->iovused);
    fprintf(stderr, "msgsize:%d  msgused:%d  msgcurr:%d  msgbytes:%d\n",
            c->msgsize, c->msgused, c->msgcurr, c->msgbytes);

}
