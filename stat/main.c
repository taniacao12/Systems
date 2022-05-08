#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main(){
  char * filename = "main.c";

  printf("\nPrinting out information about [%s]:\n", filename);

  struct stat info;

  stat(filename, &info);

  // print file size
  int size = info.st_size;
  printf(" File size: [%d]\n", size);

  // print permissions
  int perm = info.st_mode;
  printf(" Permissions: [%d]\n", perm);

  // print time of last access
  int laccess = info.st_atime;
  printf(" Time of last access: [%d]\n", laccess);

  printf("\n");
  return 0;
}
