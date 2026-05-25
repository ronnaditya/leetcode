#include<stdlib.h>
#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int* nums = malloc(sizeof(int) * (nums1Size + nums2Size));
  int numsIndex = 0;
  
  double median;
  int i = 0;
  int j = 0;
  while ((i < nums1Size || j < nums2Size) && (numsIndex < nums1Size + nums2Size)) {
    if (((i != nums1Size) && (nums1[i] <= nums2[j])) || j == nums2Size) {
      nums[numsIndex] = nums1[i];
      ++i;
      ++numsIndex;
      continue;
    }
    if ((j != nums2Size) && (nums2[j] <= nums1[i]) || i == nums1Size) {
      nums[numsIndex] = nums2[j];
      ++j;
      ++numsIndex;
      continue;
    }
  }
  
  int totalSize = nums1Size + nums2Size;
  int remainder = totalSize % 2;
  if (!remainder) {
    int l_mid = (totalSize / 2) - 1;
    int r_mid = (totalSize / 2);
    return (nums[l_mid] + nums[r_mid] / 2);
  } else {
    int mid = (totalSize - 1) / 2;
    return nums[mid];
  }
}

void main() {
  int nums1[] = {1, 3};
  int nums2[] = {2};
  printf("%f", findMedianSortedArrays(nums1, 2, nums2, 1));
}
