#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

void exitsys(const char *msg);
int main(int argc, char *argv[])
{
     int i;
     int fd;

     for (i = 1;; ++i) {
          if ((fd = open(argv[1], O_RDONLY)) < 0)  
               break;
          printf("count = %d, fd = %d\n", i, fd);
     }

     return 0;
}

void exitsys(const char *msg)
{
     perror(msg);
     exit(EXIT_FAILURE);
}
