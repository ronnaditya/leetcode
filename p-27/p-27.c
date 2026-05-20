#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  int i = 0;
  while (i < numsSize - 2) {
    if (nums[i] == val) {
      int j = i + 1;
      while (nums[j] == val && j < numsSize - 1) {
        ++j;
      }
      nums[i] = nums[j];
      nums[j] = val;
    }
    ++i;
  }

  if (nums[numsSize - 2] == val && nums[numsSize - 1] != val) {
    nums[numsSize - 2] = nums[numsSize - 1];
    nums[numsSize - 1] = val;
  }
  
  int k = 0;
  while (k < numsSize && nums[k] != val) {
    ++k;
  }

  return k;
}

void main() {
  int nums[] = {};
  removeElement(nums, 0, 0);
}
