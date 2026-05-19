#include<stdio.h>
#include<string.h>

struct translation_dict {
  char roman;
  int number;
};

struct subtractions {
  char to_be_subtracted;
  char subtracted_from[2];
};

struct translation_dict characters[] = {
  { 'I', 1},
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
  
  for (int i = 0; i < length; ++i) {
    int handled = 0;
    for (int j = 0; j < 7; ++j) {
      if (s[i] == characters[j].roman) {
        for (int k = 0; k < 3; ++k) {
          if (s[i] == subtraction_pairs[k].to_be_subtracted) {
            for (int l = 0; l < 2; ++l) {
              if (s[i + 1] == subtraction_pairs[k].subtracted_from[l]) {
                number += translate(s[i + 1]) - translate(s[i]);
                handled = 1;
                ++i;
                break;
              } 
            }
          } 
        }
      }
    }
    if (!handled) {
    number += translate(s[i]);
    }
  }
  return number;
}

void main () {
  printf("%d", romanToInt("MMMCMXCIX"));
}
