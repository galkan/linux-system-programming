#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void exitsys(const char *msg);

/* Usage: direct <file path> <executable path> */

int main(int argc, char *argv[])
{
     pid_t pid;
     int fd;

     if (argc < 3) {
           fprintf(stderr, "wrong number of arguments!..\n");

      exit(EXIT_FAILURE);

}

if ((pid = fork()) < 0)
     exitsys("fork");

if (pid == 0) {
     if ((fd = open(argv[1], O_WRONLY|O_CREAT,           S_IRUSR|S_IWUSR|S_IRGRP|S_IRGRP)) < 0) 
     exitsys("open"); 
     if (dup2(fd, STDOUT_FILENO) < 0)
          exitsys("dup2");

     close(fd);

     if (execvp(argv[2], &argv[2]) < 0)
          exitsys("execvp");

     /* unreachable code */

}

if (waitpid(pid, NULL, 0) < 0)
     exitsys("waitpid");

return 0;

}

void exitsys(const char *msg)
{
     perror(msg);
     exit(EXIT_FAILURE);
}
