#include<stdlib.h>
#include<stdio.h>

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }

  int size = 0;
  int x_copy = x;
  while (x_copy > 0) {
    x_copy = x_copy / 10;
    size += 1;
  }

  int *num_arr = malloc(sizeof(int) * size);
  int *rev_arr = malloc(sizeof(int) * size);
  int curr_digit;

  for (int i = 0; i < size; ++i) {
    curr_digit = x % 10;
    num_arr[i] = curr_digit;
    rev_arr[size - 1 - i] = curr_digit;
    x /= 10;
  }

  for (int i = 0; i < size; ++i) {
    if (num_arr[i] == rev_arr[i]) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  printf("%d", isPalindrome(12677621));
}
