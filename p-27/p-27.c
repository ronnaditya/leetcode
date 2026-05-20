#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  int i = 0;
  while (i < numsSize) {
    if (nums[i] == val) {
      // The memory address after the last item of the current array is accessed in this algorithm.
      // That's the reason for it not working, as the second to last item is replaced by the item
      // after the last memory address of the array, and the last `val` is placed at the address
      // after the array.
      int j = i + 1;
      while (nums[j] == val & j < numsSize) {
        ++j;
      }
      printf("i: %d | j: %d | nums[i]: %d | nums[j]: %d\n", i, j, nums[i], nums[j]);
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
  int nums[] = {1,2,3,2,4,3,2};
  removeElement(nums, 7, 3);
}
