#include<stdio.h>
#include<stdlib.h>

int is_palindrome(int num) {
  // Must allocate memory after knowing the size of the int.
  
  int size = 0;
  int counter_num = num;

  while (counter_num > 0) {
    counter_num = counter_num / 10;
    size += 1;
  }

  int *ptr_arr = malloc(sizeof(int) * size);

  for (int i = 0; i < size; ++i) {
    ptr_arr[i] = num % 10;
    num = num / 10;
  }

  for (int i = size - 1; i >= 0; --i) {
    printf("%d", ptr_arr[i]);
  }
  // Now, palindrome detection.
  return 0;
}

int main () {
  return is_palindrome(121463728);
}
