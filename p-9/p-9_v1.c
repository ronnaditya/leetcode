#include<stdio.h>
#include<stdlib.h>

int is_palindrome(int num) {
  int num_list[] = {};

  int i = 0;
  do {
    printf("Num List: %ld\n", num % 10);
    printf("Num: %ld\n", num / 10);
    ++i;
  } while(num > 0);
  
  printf("%ld", sizeof(num_list));
  printf("%ld", sizeof(num_list) / sizeof(num_list[0]));
  return 0;
}

int main () {
  return is_palindrome(121);
}
