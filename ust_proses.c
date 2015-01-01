#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void exitsys(const char *msg);

int g_x;

int main(int argc, char *argv[])
{
 pid_t pid;

 if ((pid = fork()) < 0)
  exitsys("fork");

 if (pid != 0) {
  g_x = 10;
  printf("parent process...\n");
 
 }
 else {
  sleep(2);
  printf("child process: %d\n", g_x);  /* 0 yazdýrýlacak */
 }

 printf("ends...\n");

 return 0;
}

void exitsys(const char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}
