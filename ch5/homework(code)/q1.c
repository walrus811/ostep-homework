#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int x = 42;
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    x = 299;
    printf("hello, I am child var: %d\n", x);
  }
  else
  {
    x = -123;
    printf("hello, I am parent var: %d\n", x);
  }

  return 0;
}