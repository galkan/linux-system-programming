#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void exitsys(const char *msg);

int main(int argc, char *argv[])
{
 if (argc < 2) {
  fprintf(stderr, "wrong number of arguments!..\n");
  exit(EXIT_FAILURE);
 }

 if (execv(argv[1], &argv[1]) < 0)
  exitsys("execl");

 printf("unreachable code!..\n");

 return 0;
}

void exitsys(const char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}
