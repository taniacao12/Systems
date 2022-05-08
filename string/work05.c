#include <stdio.h>
#include <string.h>

// strlen - Tania
int my_strlen(char *s){
  int index = 0;
  int counter = 0;
  while (s[index]) {
    counter++;
	index++;
  }
  return counter;
}

// strcpy - Tania
char *my_strcpy(char *dest, char *source){
  int index = 0;
  while (source[index]) {
	dest[index] = source[index];
	index++;
  }
  dest[index+1] = 0;
  return dest;
}

// strncpy - Tania
char *my_strncpy(char *dest, char *source, int n){
  int index = 0;
  while (index < n) {
	dest[index] = source[index];
	index++;
  }
  return dest;
}

// strcat - Ivan
char *my_strcat(char *dest, char *source ){
  char *ret = dest; // what we're returning

  //move first *char until you hit a null
  while(*dest)
    dest++;

  //copy values from the second *char until with hit a null there
  while(*source){
    *dest = *source;
    source++;
    dest++;
  }
  return ret;
}

// strncat - Ivan
char *my_strncat(char *dest, char *source, int n){
  char *ret = dest; // what we're returning

  //move first *char until you hit a null
  while(*dest)
    dest++;

  //copy values from the second *char until n reaches 0
  while(n--){
    *dest = *source;
    source++;
    dest++;
  }
  return ret;
}

// strcmp - Ivan
int my_strcmp(char *s1, char *s2){
  while(*s1 && *s2){
    // if any are larger
    if(*s1 > *s2 || *s2 > *s1){
      return *s1 - *s2;
    }
    // increment
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

// strchr - Ivan
char *my_strchr(char *s, char c){
  while(*s != c){
    if(!*s)
      return NULL;
    s++;
  }
  return s;
}

// helper for strstr
int strcmpn(char * s1, char * s2, int ln){
  char s1c[ln];
  char s2c[ln];
  strncpy(s1c, s1, ln);
  strncpy(s1c, s2, ln);

  return strcmp(s1c, s2c);
}

// strstr - Ivan
char *my_strstr(char *s1, char *s2){
  while(1){
    if(!*s1)
      return NULL;
    s1++;
  }
  return s1;
}

// some helper stuff
void reset_strings(char *s1, char *s2, char*s3){
  printf("Resetting string values... \n");
  strcpy(s1, "Amazing");
  strcpy(s2, "Strings");
}
void print_strings(char *s1, char *s2, char *s3){
  printf("Current string values: \n");
  printf("s1: [%s] \n", s1);
  printf("s2: [%s] \n", s2);
}

int main(){
  char s1[64]; char s2[64]; char s3[64];
  reset_strings(s1, s2, s3);
  print_strings(s1, s2, s3);

  //strlen test
  printf("\nTesting strlen(s1): \n");
  printf("standart: %lu \n", strlen(s1));
  //reset_strings(s1, s2, s3);
  printf("custom: %d \n", my_strlen(s1));
  //reset_strings(s1, s2, s3);

  //strcopy test
  printf("\nTesting strcopy(s1, s2): \n");
  printf("standart: [%s]\n", strcpy(s1, s2));
  reset_strings(s1, s2, s3);
  printf("custom: [%s]\n", my_strcpy(s1, s2));
  reset_strings(s1, s2, s3);

  //strncopy test
  printf("\nTesting strcopy(s1, s2, 3): \n");
  printf("standart: [%s]\n", strncpy(s1, s2, 3));
  reset_strings(s1, s2, s3);
  printf("custom: [%s]\n", my_strncpy(s1, s2, 3));
  reset_strings(s1, s2, s3);

  //strcat test
  printf("\nTesting strcat(s1, s2): \n");
  printf("standart: [%s]\n", strcat(s1, s2));
  reset_strings(s1, s2, s3);
  printf("custom: [%s]\n", my_strcat(s1, s2));
  reset_strings(s1, s2, s3);

  //strncat test
  printf("\nTesting strncat(s1, s2, 3): \n");
  printf("standart: [%s]\n", strncat(s1, s2, 3));
  reset_strings(s1, s2, s3);
  printf("custom: [%s]\n", my_strncat(s1, s2, 3));
  reset_strings(s1, s2, s3);

  //strcmp test
  printf("\nTesting strcmp(s1, s2): \n");
  printf("standart: [%d]\n", strcmp(s1, s2));
  //reset_strings(s1, s2, s3);
  printf("custom: [%d]\n", my_strcmp(s1, s2));
  //reset_strings(s1, s2, s3);

  //strchr test
  printf("\nTesting strchr(s1, 'z'): \n");
  printf("standart: [%s]\n", strchr(s1, 'z'));
  //reset_strings(s1, s2, s3);
  printf("custom: [%s]\n", my_strchr(s1, 'z'));
  //reset_strings(s1, s2, s3);

  //strstr test
  // printf("\nTesting strstr(s1, \"ng\"): \n");
  // printf("standart: [%s]\n", strstr(s1, "ng"));
  // reset_strings(s1, s2, s3);
  // printf("custom: [%s]\n", my_strstr(s1, "ng"));
  // reset_strings(s1, s2, s3);

  return 0;
}
