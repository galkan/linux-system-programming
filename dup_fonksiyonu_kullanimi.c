#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void exitsys(const char *msg);
int main(int argc, char *argv[])
{
     int fdnew;

     if ((fdnew = dup(1)) < 0)
          exitsys("dup");
     write(fdnew, "test\n", 5);
     close(fdnew); 
     return 0;
}

void exitsys(const char *msg)
{
     perror(msg);
     exit(EXIT_FAILURE);
}
