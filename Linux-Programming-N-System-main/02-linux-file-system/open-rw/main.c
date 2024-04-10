#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd; // file descriptor (bộ mô tả: đại diện cho file đó) - description (mô tả) - bản chất là 1 số nguyên
    int numb_read, numb_write;
    char buf1[12] = "hello world\n";
    char buf2[12] = "aaaaaaaaaaa";
    // assume foobar.txt is already created
    fd = open("hello.txt", O_RDWR);

    if(-1 == fd) {
        printf("open() hello.txt failed\n");
    }

    numb_write = write(fd, buf1, strlen(buf1)); // số bytes thực tế được trả về
    printf("write %d bytes to hello.txt\n", numb_write);

    lseek(fd, 2, SEEK_SET);
    write(fd, buf2, strlen(buf2));

    close(fd);

    return 0;
}