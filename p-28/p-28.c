#include<stdio.h>
#include<string.h>

int strStr(char* haystack, char* needle) {
  int haystackLength = strlen(haystack);
  int needleLength = strlen(needle);
  
  bool found = false;
  int i = 0;
  while (i <= haystackLength - needleLength) {
    int j = 0;
    while (j <= needleLength) {
      if (needle[j] == haystack[i + j] && j < needleLength) {
        ++j;
        continue;
      } else if (j == needleLength) {
        found = true;
        break;
      } else {
        break;
      }
    }
    if (found) {
      return i;
    }
    ++i;
  }
  return -1;
}

void main() {
  // Find the index of the first occurrence of the needle in the haystack.
  char* needle[] = {"all", "hell", "umb", "joy", "tess", "father"};
  char* haystack[] = {"asdfcallasdf", "sashell", "penumbra", "dsafenjoysadf", "fejhaf", "mom"};
  for (int i = 0; i < 6; ++i) {  
    printf("%d\n", strStr(haystack[i], needle[i]));
  }
}
