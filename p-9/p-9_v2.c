#include<stdio.h>
#include<stdlib.h>

int is_palindrome(int num) {
  int num_arr[3] = {};
  
  int i = 0;
  while (num > 0) {
    num_arr[i] = num % 10;
    num = num / 10;
    printf("%d\n", num);
    ++i;
  }
  
  int size = sizeof(num_arr) / sizeof(num_arr[0]);

  for (int i = 0; i < size; ++i) {
    printf("%d: %d\n", i, num_arr[i]);
  }

  return 0;
}

int main () {
  return is_palindrome(121);
}
