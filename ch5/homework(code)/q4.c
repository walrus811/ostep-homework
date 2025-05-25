#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    char *args[2];
    args[0] = strdup("ls");
    args[1] = NULL;

    execvp(args[0], args);
  }
  else
  {
  }

  return 0;
}