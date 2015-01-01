#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void exitsys(const char *msg);
int main(int argc, char *argv[])
{
     int fd;
     int i;

     if ((fd = open("test.txt", O_WRONLY|O_CREAT, 
     S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0)
          exitsys("open");

     if (dup2(fd, STDOUT_FILENO) < 0)
          exitsys("dup2"); 
     for (i = 0; i < 10; ++i)
          printf("%d\n", i);

     close(fd); 
     return 0;
}

void exitsys(const char *msg)
{
     perror(msg);
     exit(EXIT_FAILURE);
}
