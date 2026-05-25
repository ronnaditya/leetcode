#include<stdio.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char* s) {
  int longest = 0;
  int i = 0;
  while (s[i] != 0) {
    int j = 0;
    while (s[j] != 0) {
      for (int k = j + 1; k >= i; --k) {
        if (s[k] == s[j]) {
          if (j - i > longest) {
            printf("in\n");
            printf("i: %d | j: %d\n", i, j);
            longest = j - i;
          }
        }
      }
      ++j;
    }
    ++i;
  }
  return longest + 1;
}

void main() {
  printf("%d", lengthOfLongestSubstring("ret"));
}
