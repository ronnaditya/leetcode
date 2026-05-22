#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  if (numsSize == 1) {return 1;}
  int i = 0;
  int non_uniques = 0;
  while (i < numsSize - non_uniques) {
    int j = i + 1;
    while (j <= numsSize) {
      if (j < numsSize && nums[i] == nums[j]) {
        ++j;
        ++non_uniques;
        continue;
      } else {
        break;
      }
    }
    int l = j - 1;
    while (l > i) {
      int m = l;
      while (m < numsSize - 1) {
        nums[m] = nums[m + 1];
        ++m;
      }
      nums[numsSize - 1] = nums[i];
      --l;
    }
    ++i;
  }
  return numsSize - non_uniques;
}

void main() {
  // int nums[] = {1, 2};
  int nums[] = {1, 2, 2, 2};
  printf("%d", removeDuplicates(nums, 4));
}
