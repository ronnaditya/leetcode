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
  
  // Array construction and comparison
  int odd = size % 2;

  int mid;

  if (odd) {
    mid = size / 2;
  } else {
    mid = size / 2;
  }
  
  int *arr_l = malloc(sizeof(int) * mid);
  int *arr_r = malloc(sizeof(int) * mid);
   
  printf("Mid: %d\n", mid);
  if (odd) {
    for (int i = mid; i < size; ++i) {
      arr_l[i] = ptr_arr[mid + i];
      printf("%d\n", arr_l[i]);
    }
  }

  return 0;
}

int main () {
  return is_palindrome(121463728);
}
