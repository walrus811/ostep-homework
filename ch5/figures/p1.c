#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  printf("Hello, World (pid:%d)\n", (int)getpid());

  int rc = fork();

  if(rc < 0){
    fprintf(stderr, "Fork failed\n");
    exit(1);
  } else if(rc == 0) {
    // Child process
    printf("hello, I am child (pid:%d)\n", (int)getpid());
  } else {
    // Parent process
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
  }

  return 0;
}