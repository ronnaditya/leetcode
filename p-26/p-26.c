#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  int i = 0;
  while (i < numsSize) {
    int j = i + 1;
    while (nums[i] == nums[j]) {
      ++j;
    }
    int l = j - 1;
    while (l > i) {
      int m = l;
      while (m < numsSize) {
        nums[m] = nums[m + 1];
        ++m;
      }
      nums[numsSize - 1] = nums[i];
      --l;
    }
    ++i;
  }
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
