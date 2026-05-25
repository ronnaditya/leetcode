#include<stdlib.h>
#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int totalSize = nums1Size + nums2Size;
  int odd = totalSize % 2;

  if (!odd) {
    printf("ODD");
    int currentValue;
    int currentIndex = 0;
    int medianIndex = (totalSize - 1) / 2;
    int i = 0;
    int j = 0;
    while (currentIndex <= medianIndex) {
      if (nums1[i] < nums2[j]) {
        currentValue = nums1[i];
        ++i;
        ++currentIndex;
      } else if (nums2[j] < nums1[i]) {
        currentValue = nums2[j];
        ++j;
        ++currentIndex;
      }
    }
    return currentValue;
  } else {
    printf("EVEN");
    int lValue;
    int rValue;
    int lMedianIndex = (totalSize / 2) - 1;
    int rMedianIndex = (totalSize / 2);
    int currentIndex = 0;
    int i = 0;
    int j = 0;
    while (currentIndex != lMedianIndex) {
      if (nums1[i] < nums2[j]) {
        lValue = nums1[i];
        ++i;
        ++currentIndex;
      } else if (nums2[j] < nums1[i]) {
        lValue = nums2[j];
        ++j;
        ++currentIndex;
      }
    if (nums1[i] < nums2[j]) {
        rValue = nums1[i];
    } else {
        rValue = nums2[j];
    }
    return (lValue + rValue) / 2;
    }
  }
}

void main() {
  int nums1[] = {1, 3};
  int nums2[] = {2, 4};
  printf("%f", findMedianSortedArrays(nums1, 2, nums2, 1));
}
