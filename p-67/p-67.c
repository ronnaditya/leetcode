#include<stdio.h>
#include<stdlib.h>

char* addBinary(char* a, char* b) {
  int lena = 0;
  int lenb = 0;

  while (a[lena] != 0) {
    ++lena;
  }
  while (b[lenb] != 0) {
    ++lenb;
  }

  char* chars = malloc(sizeof(char) * 100000);
  
  int carry = 0;
  if (lena > lenb) {
    int diff = lena - lenb;
    for (int i = lenb - 1; i >= 0; --i) {
      if (a[i + diff] == '0' && b[i] == '0') {
        if (carry) {
          chars[i + diff] = '1';
          carry = 0;
        } else {
          chars[i + diff] = '0';
        }
      } else if ((a[i + diff] == '0' && b[i] == '1') || (a[i + diff] == '1' && b[i] == '0')) {
        if (carry) {
          chars[i + diff] = '0';
          carry = 1;
        } else {
          chars[i + diff] = '1';
        }
      } else {
        if (carry) {
          chars[i + diff] = '1';
        } else {
          chars[i + diff] = '0';
          carry = 1;
        }
      }
    }
    return chars;
  } else {

  }
}

void main() {
  char* a = "110110";
  char* b = "110";
  char* answer = addBinary(a, b);
  for (int i = 0; i < 6; ++i) {
    printf("%d", answer[i]);
  }
}
