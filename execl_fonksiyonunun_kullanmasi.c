#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void exitsys(const char *msg);

int main(int argc, char *argv[])
{
 printf("starts...\n");

 if (execl("/bin/ls", "/bin/ls", "-l", (char *) NULL) < 0)
  exitsys("execl");

 printf("unreachable code!..\n");

 return 0;
}

void exitsys(const char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}
