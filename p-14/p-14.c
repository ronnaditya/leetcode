#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
  int shortest = 0;
  for (int i = 0; i < strsSize; ++i) {
    int j = 0;
    while (strs[i][j] != 0) {
      ++j;
    }

    if (shortest == 0 & j != 0) {
      shortest = j;
    } else if ( shortest != 0 & j < shortest) {
      shortest = j;
    }
  }
  
  // to check all strings, it is difficult to set a single comparison statement, since the size of the array
  // of strings will differ from case to case. instead, we can just compare two at a time.
  int common = 0;
  int i = 0;
  while (i < shortest) {
    bool common_bool = true;
    for (int j = 0; j < strsSize - 1; ++j) {
      if (strs[j][i] == strs[j + 1][i]) {
        continue;
      } else {
        common_bool = false;
        break;
      }
    }
    if (common_bool) {
      common += 1;
    }
    ++i;
  }
  // char* ptr_commonPrefix = malloc(sizeof(common_prefix));
  // ptr_commonPrefix = &common_prefix;
  // return common_prefix;
}

void main() {
  char* strs[] = {"flow", "flower", "flight"};

  longestCommonPrefix(strs, 3);
}
