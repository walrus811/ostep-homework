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
    printf("child\n pid: %d\n", (int)getpid());
  }
  else
  {
    int wait_status = waitpid(rc, NULL, 0);
    printf("parent\n, wait status: %d\n", wait_status);
  }

  return 0;
}