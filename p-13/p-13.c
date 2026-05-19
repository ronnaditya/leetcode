#include<stdio.h>
#include<string.h>

struct dict {
  char roman;
  int number;
};

struct dict characters[] = {
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
};

int translate(char roman) {
  for (int i = 0; i < 7; ++i) {
    if (roman == characters[i].roman) {
      return characters[i].number;
    }
  }
}

int romanToInt(char* s) {
  int length = strlen(s);

  char autonomous[] = {'X', 'C', 'V', 'L', 'D'};
  char dependents[] = {'I', 'X', 'C', 'M'};
  int autonomous_length = 5;
  int dependents_length = 4;
  
  int number = 0;
  int i = 0;
  while (i < length) {
    for (int j = 0; j < dependents_length; ++j) {
      if (s[i] == dependents[j]) {
        for (int k = 0; k < autonomous_length; ++k) {
          if (s[i + 1] == autonomous[k]) {
            number += translate(s[i + 1]) - translate(s[i]);
            ++i;
            break;
          } else {
            number += translate(s[i]);
          }
        }
      }
    }
  ++i;
  }
  return number;
}

void main () {
  printf("%d", romanToInt("XL"));
}
