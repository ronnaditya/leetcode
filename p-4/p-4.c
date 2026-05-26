#include<stdlib.h>
#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int totalSize = nums1Size + nums2Size;
  int odd = totalSize % 2;
  int medianIndex;
  if (odd) {
    medianIndex = (totalSize - 1) / 2;
  } else {
    medianIndex = (totalSize / 2);
  }
  int dummy = -1000;
  int* ptrLMedian = &dummy;
  int* ptrRMedian = &dummy;
  int i = 0;
  int j = 0;
  while ((i + j) <= medianIndex) {
    if (i < nums1Size) {
      if (j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
          ptrLMedian = ptrRMedian;
          ptrRMedian = &nums1[i];
          ++i;
          continue;
        }
      } else {
        ptrLMedian = ptrRMedian;
        ptrRMedian = &nums1[i];
        ++i;
        continue;
      }
    }
    if (j < nums2Size) {
      if (i < nums1Size) {
        if (nums1[i] >= nums2[j]) {
          ptrLMedian = ptrRMedian;
          ptrRMedian = &nums2[j];
          ++j;
          continue;
        }
      } else {
        ptrLMedian = ptrRMedian;
        ptrRMedian = &nums2[j];
        ++j;
        continue;
      }
    }
  }
  if (odd) {
    return *ptrRMedian;
  } else {
    return (*ptrRMedian + *ptrLMedian) / 2.0;
  }
}

void main() {
  int nums1[] = {1, 3};
  int nums2[] = {2, 7};
  printf("%f", findMedianSortedArrays(nums1, 2, nums2, 2));
  printf("ddd%d", (-1 + 0) / 2);
}
