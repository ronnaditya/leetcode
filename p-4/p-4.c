#include<stdlib.h>
#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int medianIndex;
  int totalSize = nums1Size + nums2Size;
  bool odd = totalSize % 2;
  if (odd) {
    int medianIndex = (totalSize - 1) / 2;
  } else {
    medianIndex = (totalSize / 2) - 1;
  }
  
  int i = 0;
  int j = 0;
  int arrIndex = 0;
  int recent;
  while ((arrIndex < medianIndex) && (i < nums1Size || j < nums2Size)) {
    if (nums1[i] < nums2[j]) {
      ++arrIndex;
      ++i;
      recent = 1;
    } else {
      ++arrIndex;
      ++j;
      recent = 2;
    }
  }
  if (odd) {
    if (nums1[i] < nums2[j] && recent == 1) {
      return nums1[i];
    } else {
      return nums2[j];
    }
  } else {
    int l_median = 0;
    int r_median = 0;
    if (nums1[i] < nums2[j]) {
      l_median = nums1[i];
      ++i;
    } else {
      l_median = nums2[j];
      ++j;
    }
    if (nums1[i] < nums2[j]) {
      r_median = nums1[i];
      ++i;
    } else {

      r_median = nums2[j];
      ++j;
    }
    float median = (l_median + r_median) / 2.0;
    return median;
  }
}

void main() {
  int nums1[] = {1, 3};
  int nums2[] = {2};
  printf("%f", findMedianSortedArrays(nums1, 2, nums2, 1));
}
