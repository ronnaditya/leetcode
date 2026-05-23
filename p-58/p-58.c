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
  printf("%d", lastCharacter);
}

void main() {
  lengthOfLastWord("abcd     d  ");
}
