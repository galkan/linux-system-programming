#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 

void exitsys(const char *msg);

int main(int argc, char *argv[])
{
     int fd;
     int i;
     close(1); 

     if ((fd = open("a.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP)) < 0)
          exitsys("open");

     for (i = 0; i < 100; ++i)
          printf("%d\n", i); 
     return 0;
} 

void exitsys(const char *msg)
{
     perror(msg);
     exit(EXIT_FAILURE);
}
