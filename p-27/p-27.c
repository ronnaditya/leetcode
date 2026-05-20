#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  int i = 0;
  while (i < numsSize) {
    if (nums[i] == val) {
      int j = i + 1;
      while (nums[j] == val) {
        // stack overflow
        ++j;
      }
      nums[i] = nums[j];
      nums[j] = val;
    }
    ++i;
  }

  for (int i = 0; i < numsSize; ++i) {
    printf("%d", nums[i]);
  }
}


void main() {
  int nums[] = {1,2,3,2,4,3,2,2,5,7,8,9,0};
  removeElement(nums, 13, 2);
}
