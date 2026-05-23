#include<stdio.h>

// Maybe, coding all day is exactly what I need.
int lengthOfLastWord(char* s) {
  int lastCharacter = 0;
  int i = 0;
  while (s != 0) {
    if (s != " ") {
      lastCharacter = i;
    }
  }
  printf("%d", lastCharacter);
}

void main() {

}
