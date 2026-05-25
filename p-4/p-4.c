#include<stdlib.h>
#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int currentIndex = 0;
  int totalSize = nums1Size + nums2Size;
  int remainder = totalSize % 2;
  
  if (remainder) { // This code finds the mode!
    int medianIndex = (totalSize - 1) / 2;
    int i = 0;
    int j = 0;
    while (currentIndex != median) {
      if (nums1[i] < nums2[j]) {
        ++i;
        ++currentIndex;
      } else {
        ++j;
        ++currentIndex;
      }
    }
  }
}

void main() {
  int nums1[] = {1, 3};
  int nums2[] = {2};
  printf("%f", findMedianSortedArrays(nums1, 2, nums2, 1));
}
