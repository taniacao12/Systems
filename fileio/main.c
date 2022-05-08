#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>


/*
  File reading and writing goes here
  1. write some random numbers to fd_write
  2. close fd_write
  3. open fd_read with reading
  4. read from fd_read and print the numbers out
  5. close fd_read
*/

int main(){
    int fd_write, fd_read;
	
    // open file that doesn't exist
    printf("\nAttemting to open [missing_file.txt] for writing only\n");
    fd_write = open("missing_file.txt", O_WRONLY);

    if(fd_write == -1)
	printf(" File not found (file descriptor: %d)\n", fd_write);
    else
	printf(" File found! (file descriptor: %d)\n", fd_write);

    // open file that we know exists
    printf("\nAttemting to open [file.txt] for writing\n");
    fd_write = open("file.txt", O_WRONLY | O_CREAT);

    if(fd_write == -1)
	printf(" File not found (file descriptor: %d)\n", fd_write);
    else
	printf(" File found! (file descriptor: %d)\n", fd_write);

    //write random numbers to fd_write
    size = write(fd_write, 123456789, 10);

    //close fd_write
    printf("\nClosing writing of [file.txt]\n");
    if(!close(fd_write))
	printf(" File closed!\n");
    else
	printf(" Something went wrong!\n");

    // open fd_read with reading
    printf("\nAttemting to open [file.txt] for reading\n");
    fd_read = open("file.txt", O_RDONLY | O_CREAT);

    if(fd_read == -1)
	printf(" File not found (file descriptor: %d)\n", fd_read);
    else
	printf(" File found! (file descriptor: %d)\n", fd_read);

    // read from fd_read and print stuff out
    printf(fd_read(fd_read, size));

    // close fd_read
    printf("\nClosing reading of [file.txt]\n");
    if(!close(fd_read))
	printf(" File closed!\n");
    else
	printf(" Something went wrong!\n");

    return 0;
}
