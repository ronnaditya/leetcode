#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < m + n) {
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
          ++j;
        }
      } else {
        break;
      }
    } else {
      for (int l = k; l < nums2Size; ++l) {
        printf("Up in here\n");
        nums1[i] = nums2[l];
        ++i;
      break;
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
