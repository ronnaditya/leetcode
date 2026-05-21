#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {

  for (int i = 0; i < numsSize; ++i) {
    printf("%d\n", nums[i]);
  }
}

void main() {
  // Make a set out of the passed list, albeit maintaining the length of the list itself,
  // and return the number of elements in the set.
  // int nums[] = {1,1,2,3,3,3,3,4,5};
  // int nums[] = {1, 2, 3, 3, 4,4,5,5,5,6,6};
  int nums[] = {1, 1, 2};
  removeDuplicates(nums, 3);
}
