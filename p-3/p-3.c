#include<stdio.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char* s) {
  int longest = 0;
  int i = 0;
  while (s[i] != 0) {
    int length = 0;
    int j = i + 1;
    while (s[j] != 0) {
      if (s[j] == s[i]) {
        if (length > longest) {
          longest = length;
        break;
        }
      }
      ++length;
      ++j;
    }
    ++i;
  }
  return longest;
}

void main() {
  printf("%d", lengthOfLongestSubstring("asdfsadf"));
}
