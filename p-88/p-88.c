#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = 0;
  int j = 0;

  while (i < m + n) {
    if (nums1[i] == 0 & i > m) {
      nums1[i] = nums2[j];
      ++j;
      ++i;
      continue;
    }
    if (i < nums1Size & j < nums2Size) {
      if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        for (int k = m + n - 1; k > i; --k) {
          nums1[k] = nums1[k - 1];
        }
        nums1[i] = nums2[j];
        ++i;
        ++j;
        continue;
      }
    }
    ++i;
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
