#include<stdio.h>
#include<string.h>

struct translation_dict {
  char roman;
  int number;
};

struct translation_dict characters[] = {
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
};

struct subtractions {
  char to_be_subtracted;
  char subtracted_from[2];
};

int translate(char roman) {
  for (int i = 0; i < 7; ++i) {
    if (roman == characters[i].roman) {
      return characters[i].number;
    }
  }
}

int romanToInt(char* s) {
  // MMMCMXCIX
  // MMMCLXXXVIII simple addition would work here. so that means that i need to recognise
  //   deviants from the norm of simple addition. how do i do that? i would have to check
  //   the next character.
  struct translation_dict characters[] = {
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
  };

  struct subtractions ones = {'I', {'V', 'X'}};
  struct subtractions tens = {'X', {'L', 'C'}};
  struct subtractions hundreds = {'C', {'D', 'M'}};

  struct subtractions subtraction_pairs[] = {
    ones,
    tens,
    hundreds
  };

  int length = strlen(s);
  
  int number = 0;
  int negative = false;
  int i = 0;
  while (i < length) {
    for (int j = 0; j < 3; ++j) {
      if (s[i] == subtraction_pairs[j].to_be_subtracted) {
        for (int l = 0; l < 2; ++l) {
          if (s[i + 1] == subtraction_pairs[j].subtracted_from[l]) {
            number += translate(s[i + 1]) - translate(s[i]);
            ++i;
          }
        }
      }
    }
    ++i;
  }
  return number;
}

void main () {
  printf("%d", romanToInt("CM"));
}
