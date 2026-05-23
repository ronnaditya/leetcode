#include<stdio.h>


int searchInsert(int* nums, int numsSize, int target) {
  int answer = 0;
  for (int i = 0; i < numsSize + 1; ++i) {
    if ((nums[i] == target || nums[i] > target)) {
      return i;
      break;
    }
  }
  return numsSize;
}

void main() {
  int nums[] = {1, 3, 5, 6};
  printf("%d", searchInsert(nums, 4, 7));
}
