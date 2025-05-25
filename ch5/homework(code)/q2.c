#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int fd = open("q2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("hello, I am child fd: %d\n", fd);

    const char *msg = "Hello, from a child!\n";
    ssize_t bytes_written = write(fd, msg, strlen(msg));

    if (bytes_written < 0)
    {
      perror("write failed");
      close(fd);
      exit(1);
    }
  }
  else
  {
    printf("hello, I am parent fd: %d\n", fd);
    const char *msg = "Hello, from a parent!\n";
    ssize_t bytes_written = write(fd, msg, strlen(msg));

    if (bytes_written < 0)
    {
      perror("write failed");
      close(fd);
      exit(1);
    }
  }

  close(fd);
  return 0;
}