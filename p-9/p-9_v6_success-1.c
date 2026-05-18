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
  
  int mid;
  int *arr_l;
  int *arr_r;

  int odd = size % 2;

  if (odd) {
    mid = size / 2;
    arr_l = malloc(sizeof(int) * (mid - 1));
    arr_r = malloc(sizeof(int) * (mid - 1));
  } else {
    mid = size / 2;
    arr_l = malloc(sizeof(int) * mid);
    arr_r = malloc(sizeof(int) * mid); 
  }
   
  for (int i = 0; i < mid; ++i) {
    arr_l[i] = ptr_arr[i];
    arr_r[i] = ptr_arr[size - 1 - i];
  }

  for (int i = 0; i < mid; ++i) {
    if (arr_l[i] == arr_r[i]) {
      continue;
    } else {
      return false;
    }
  }

  return true;
}

int main () {
  return is_palindrome(12344321);
}
