#include<stdlib.h>
#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int totalSize = nums1Size + nums2Size;
  int odd = totalSize % 2;
  int medianIndex = (totalSize / 2) - 1; // Right median if totalSize is even
  int* ptrLMedian;
  int* ptrRMedian;
  int i = 0;
  int j = 0;
  while (i + j <= medianIndex) {
    printf("IN");
    if (i < nums1Size || j >= nums2Size) {
      ptrLMedian = ptrRMedian;
      ptrRMedian = &nums1[i];
      ++i;
    } else {
      ptrLMedian = ptrRMedian;
      ptrRMedian = &nums2[j];
      ++j;
    }
    printf("i: %d | j: %d\n", i, j);
  }
  if (odd) {
    return *ptrRMedian;
  } else {
    return (*ptrRMedian + *ptrLMedian) / 2.0;
  }
}

void main() {
  int nums1[] = {1, 3};
  int nums2[] = {2};
  printf("%f", findMedianSortedArrays(nums1, 2, nums2, 1));
}
