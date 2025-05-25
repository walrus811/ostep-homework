#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    close(STDOUT_FILENO);
    printf("child\n");
  }
  else
  {
    printf("parent\n");
  }

  return 0;
}