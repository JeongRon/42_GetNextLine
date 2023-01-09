#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char buf[100];
    
    fd = open("test.txt", O_RDONLY);

    if (fd < 1)
        printf("fd_error");
    read(fd, buf, sizeof(buf));
    printf("%s", buf);
    close(fd);
    return(0);
}