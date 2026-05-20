#include<stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    
}

void main() {
  char* strings[] = {"flow", "flower", "flight"};

  printf("%s", longestCommonPrefix(strings, 3)); // array-to-pointer decay
}
