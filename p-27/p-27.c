#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  int i = 0;
  while (i < numsSize - 1) {
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
  
  int k = 0;
  while (k < numsSize && nums[k] != val) {
    ++k;
  }
  
  return k;
}

void main() {
  int nums[] = {2,3,4,2};
  removeElement(nums, 4, 2);
}
