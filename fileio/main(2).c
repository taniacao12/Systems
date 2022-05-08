#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int main(){
  FILE *file;
  char text[100];

  // open file (create if it doesn't exist)
  printf("\nOpening [file.txt] for writing...\n");
  file = fopen("file.txt", "w");

  // write in file
  printf("\nWriting in [file.txt]...\n");
  fprintf(file, "Testing fprintf...\n");
  fputs("Testing fputs...\n", file);

  //close file
  printf("\nClosing writing of [file.txt]\n");
  fclose(file);

  // open file (create if it doesn't exist)
  printf("\nOpening [file.txt] for reading...\n");
  file = fopen("file.txt", "r");

  // read file and print its contents
  fgets(text, 100, file);
  printf("1: %s", text);
  fgets(text, 100, file);
  printf("2: %s", text);

  //close file
  printf("\nClosing writing of [file.txt]\n");
  fclose(file);

  return 0;
}