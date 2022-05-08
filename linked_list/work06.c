#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare struct
struct student {
  char osis[10]; // student osis (always 10)
  char* name; // student year
  unsigned short yearof; // student year
  unsigned short curyear;
};

struct student return_example(){
  struct student new;
  // asign osis randomly
  int i;
  for(i = 0; i < 9; i++){
      new.osis[i] = 48 + (rand() % 10);
  }
  new.osis[9] = 0; // null terminator
  new.name = "Bob Ross";
  new.yearof = 2020;
  new.curyear = 2018;
  return new;
}

void promote(struct student in) {
	while (in.curyear != in.yearof) {
		in.curyear++;
		printf("\n");
		print_student(in);
	}
	printf("\nCONGRADULATIONS! YOU HAVE GRADUATED.\n\n");
}

void print_student(struct student in){
  printf("INFORMATION FOR STUDENT [%s]:\n", in.name);
  printf("Osis number: %s \n", in.osis);
  printf("Graduation year: %hu\n", in.yearof);
  printf("Current year: %hu\n", in.curyear);
}

int main(){
  srand(time(NULL));

  printf("\n");

  struct student rand_student;
  rand_student = return_example();
  print_student(rand_student);
	promote(rand_student);

  return 0;
}
