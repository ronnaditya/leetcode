#include<stdio.h>

struct dict {
  char roman;
  int number;
};

int romanToInt(char* s) {
  struct dict I;
  struct dict V;
  struct dict X;
  struct dict L;
  struct dict C;
  struct dict D;
  struct dict M;

  struct dict characters[] = {
    I,
    V,
    X,
    L,
    C,
    D,
    M
  };

  I.roman = 'I';
  I.number = 1;
  V.roman = 'V';
  V.number = 5;
  X.roman = 'X';
  X.number = 10;
  L.roman = 'L';
  L.number = 50;
  C.roman = 'C';
  C.number = 100;
  D.roman = 'D';
  D.number = 500;
  M.roman = 'M';
  M.number = 1000;

  for (int i = 0; i < 7; ++i) {
    printf("%c\n", characters[i].roman);
  }
}

void main () {
  romanToInt("dsaf");
}
