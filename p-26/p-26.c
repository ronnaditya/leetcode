#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  int occurred[] = {};
  int k = 0;
  int i = 0;
  while (i < numsSize) {
    int current = nums[i];
    bool _occurred = false;
    int j = 0;
    while (j < k) {
      if (current == occurred[j]) {
        _occurred = true;
        break;
      }
      ++j;
    }
    if (!_occurred) {
      occurred[k] = current;
      ++k;
    } else {
      printf("In here");
      for (int i = numsSize - 1; i > 0; --i) {
        nums[i - 1] = nums[i];
      }
      nums[numsSize - 1] = current;
    }
    ++i;
  }
  for (int i = 0; i < numsSize; ++i) {
    printf("%d\n", nums[i]);
  }
  printf("k: %d\n", k);
}

void main() {
  // Make a set out of the passed list, albeit maintaining the length of the list itself,
  // and return the number of elements in the set.
  int nums[] = {0,0,0,1,1,2,3,3,3,3,4,5};
  removeDuplicates(nums, 12);
}
