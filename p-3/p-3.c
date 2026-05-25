#include<stdio.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char* s) {
  int longest = 0;
  int i = 0;
  while (s[i] != 0) {
    int j = i;
    int length = 0;
    bool repeat = false;
    while (s[j] != 0 && !repeat) {
      char next = s[j + 1];
      for (int k = i; k <= j; ++k) {
        if (s[k] == next) {
          repeat = true;
          break;
        }
      }
      ++length;
      ++j;
      if (length > longest) {
        longest = length;
      }
    }
    ++i;
  }
  return longest;
}

void main() {
  printf("%d", lengthOfLongestSubstring("abcabcbb"));
}
