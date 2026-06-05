#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int j = 0;
  int k = 0;
  int i = 0;
  while (i < n) {
    printf("i: %d | j: %d | k: %d\n", i, j, k);
    if (nums1[j] < nums2[k]) {
      ++j;
    } else if (nums1[j] == nums2[k]) {
      for (int l = nums1Size; l > j; --l) {
        nums1[l] = nums1[l - 1];
      }
    } else if (k < nums2Size & nums1[j] > nums2[k]) {
      for (int l = nums1Size - 1; l > j; --l) {
        nums1[l] = nums1[l - 1];
      }
      nums1[j] = nums2[k];
      ++j;
      ++k;
    } else {
      nums1[i] = 0;
    }
    ++i;
  }
}

void main() {
  int* arr1 = malloc(sizeof(int) * 14);
  memcpy(arr1, (int[]){1,2,2,3,3,4,5}, sizeof(int) * 7);
  int arr2[] = {1,3,3,7,7,8,10};
  merge(arr1, 7, 12, arr2, 7, 2);

  for (int i = 0; i < 12; ++i) {
    printf("%d", arr1[i]);
  }
}
