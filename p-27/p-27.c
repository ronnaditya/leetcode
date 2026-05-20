#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  int i = 0;
  int vals = 0;
  while (i < numsSize) {
    if (nums[i] == val & i < numsSize - 2) {
      int j = i + 1;
      while (nums[j] == val & j < numsSize) {
        ++j;
      }
      nums[i] = nums[j];
      nums[j] = val;
    } else if (nums[i] == val & nums[i + 1] != val) {
      nums[i] = nums[i + 1];
      nums[i + 1] = val;
      break;
    }
    ++i;
  }

  for (int i = 0; i < numsSize; ++i) {
    printf("%d", nums[i]);
  }
}


void main() {
  int nums[] = {1,2,3,2,4,3,2};
  removeElement(nums, 7, 3);
}
