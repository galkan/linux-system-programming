#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void exitsys(const char *msg);

int main(int argc, char *argv[])
{
 char *args[] = {"/bin/ls", "-l", "-i", NULL};

 if (execv("/bin/ls", args) < 0)
  exitsys("execl");

 printf("unreachable code!..\n");

 return 0;
}

void exitsys(const char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}
