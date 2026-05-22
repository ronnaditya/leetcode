#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  if (numsSize == 1) {return 1;}
  int i = 0;
  int non_uniques = 0;
  while (i < numsSize - k) {
    // this i don't understand the mechanics of is it really the case that
    // having found k unique elements, the rest of the array contains non-uniqye elements?
    int j = i + 1;
    bool unique = false;
    while (j < numsSize) { // the problem does not lie here, as it the incremental check should be till the end
      if (nums[i] == nums[j]) {
        ++j;
        ++non_uniques;
        continue;
      } else { // captures two conditions of uniqueness: difference, and reaching the end of the array
        unique = true;
        break;
      }
    }
    if (unique) {
      printf("Increasing");
      ++k;
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
  return k;
}

void main() {
  // int nums[] = {1, 2};
  int nums[] = {1, 2, 2, 2};
  printf("%d", removeDuplicates(nums, 4));
}
