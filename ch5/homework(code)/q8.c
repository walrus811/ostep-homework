#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  int pipefd[2];
  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    exit(1);
  }

  pid_t child1 = fork();
  if (child1 < 0)
  {
    perror("fork");
    exit(1);
  }

  if (child1 == 0)
  {
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    printf("hey you!\n, from %d ", getpid());
    exit(0);
  }

  pid_t child2 = fork();
  if (child2 < 0)
  {
    perror("fork");
    exit(1);
  }

  if (child2 == 0)
  {
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);

    char buffer[128];
    fgets(buffer, sizeof(buffer), stdin);
    printf("Child 2 received: %s", buffer);
    exit(0);
  }

  close(pipefd[0]);
  close(pipefd[1]);
  wait(NULL);
  wait(NULL);

  return 0;
}