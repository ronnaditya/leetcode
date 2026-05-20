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
    } else {
      break;
    }
    ++i;
  }
  
  char* ptr_commonPrefix = malloc(sizeof(char) * common + 1);
  for (int i = 0; i < common; ++i) {
    ptr_commonPrefix[i] = strs[0][i];
  }

  ptr_commonPrefix[common] = '\0';

  return ptr_commonPrefix;
}

void main() {
  char* strs[] = {"cower", "cold", "clove"};

  printf("%s", longestCommonPrefix(strs, 3));
}
