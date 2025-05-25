#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int pipefd[2];
  pipe(pipefd);

  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    close(pipefd[0]);
    printf("hello\n");
    write(pipefd[1], "x", 1);
    close(pipefd[1]);
  }
  else
  {
    close(pipefd[1]);
    char buf;
    read(pipefd[0], &buf, 1);
    printf("goodbye\n");
    close(pipefd[0]);
  }

  return 0;
}