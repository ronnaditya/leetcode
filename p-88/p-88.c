#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = m + n - 1;
  int j = m - 1;
  int k = n - 1;

  while (k >= 0) {
    if (j >= 0 & nums1[j] > nums2[k]) {
      nums1[i--] = nums1[j--];
    } else {
      nums1[i--] = nums2[k--];
    }
  }
}

void main() {
  int arr1[] = {1,2,3,0,0,0};
  int arr2[] = {2,5,6};
  merge(arr1, 3, 3, arr2, 3, 3);

  for (int i = 0; i < 6; ++i) {
    printf("%d", arr1[i]);
  }
}
