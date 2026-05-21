#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  // Difference is the mark of uniquencess.
  int i = 0;
  while (i < numsSize) {
    if (nums[i] == nums[i + 1]) {
      int tmp = nums[i + 1];
      for (int j = i + 1; j < numsSize - 1; ++j) {
        printf("%d switched with %d\n", nums[j], nums[j + 1]);
        nums[j] = nums[j + 1];
      }
      nums[numsSize - 1] = tmp;
    }
    ++i;
  }

  for (int i = 0; i < numsSize; ++i) {
    printf("%d", nums[i]);
  }

}

void main() {
  // Make a set out of the passed list, albeit maintaining the length of the list itself,
  // and return the number of elements in the set.
  int nums[] = {1,1,2,3,3,3,3,4,5};
  removeDuplicates(nums, 9);
}
