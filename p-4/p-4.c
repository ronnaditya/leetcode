#include<stdlib.h>
#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int* nums = malloc(sizeof(int) * (nums1Size + nums2Size));
  int numsIndex = 0;
  
  double median;
  int i = 0;
  int j = 0;
  while ((i < nums1Size || j < nums2Size) && (numsIndex < nums1Size + nums2Size)) {
    if (nums1[i] < nums2[j] && i != nums1Size) {
      nums[numsIndex] = nums1[i];
      ++i;
    }
    if (nums2[j] < nums1[i]) {
      nums[numsIndex] = nums2[j];
      ++j;
    }
    ++numsIndex;
  }

  for (int i = 0; i < numsIndex; ++i) {
    printf("%d\n", nums[i]);
  }
}

void main() {
  int nums1[] = {1, 2, 3, 4, 5, 6};
  int nums2[] = {2, 3, 4};
  findMedianSortedArrays(nums1, 6, nums2, 3);
}
