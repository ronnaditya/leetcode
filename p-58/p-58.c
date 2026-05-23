#include<stdio.h>

int lengthOfLastWord(char* s) {
  int lastCharacter = 0;
  int i = 0;
  while (s[i] != 0) {
    if (s[i] != ' ') {
      lastCharacter = i;
    }
    ++i;
  }

  if (s == "") {
    return 0;
  }

  if (i == 1 || lastCharacter == 0) {
    return 1;
  }

  int j = lastCharacter;
  while (j >= 0 && s[j] != ' ') {
    --j;
  }

  return lastCharacter - j;
}

void main() {
  printf("%d", lengthOfLastWord("day"));
}
