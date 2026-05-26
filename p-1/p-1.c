#include<stdlib.h>
#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int* targetIndices = malloc(sizeof(int) * 2);
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if (nums[i] + nums[j] == target) {
        *returnSize = 2;
        targetIndices[0] = i;
        targetIndices[1] = j;
        return targetIndices;
      }
    }
  }
  *returnSize = 0;
  return targetIndices;
}
