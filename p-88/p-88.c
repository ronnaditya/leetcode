#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < m) {
    printf("i: %d | j: %d | k: %d\n", i, j, k);
    if (j < nums1Size) {
      if (k < nums2Size) {
        if (nums1[j] < nums2[k]) {
          ++j;
        } else {
          for (int l = m - 1; l > j; --l) {
            nums1[l] = nums1[l - 1];
          }
          nums1[j] = nums2[k];
          ++k;
        }
      } else {
        break;
      }
    } else {
      for (int l = k; k < nums2Size; ++k) {
        nums1[i] = nums2[l];
        ++i;
      break;
      }
    }
    ++i;
  }
}

void main() {
  int arr1[] = {1,1,2,3,3,3,4,5,6,0,0,0};
  int arr2[] = {1,3,3,7,7,8,10};
  merge(arr1, 9, 12, arr2, 7, 3);

  for (int i = 0; i < 12; ++i) {
    printf("%d", arr1[i]);
  }
}
