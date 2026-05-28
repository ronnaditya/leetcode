#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Chars {
  char* chars;
  int len;
};

char* addBinary(char* a, char* b) {
  int i = 0;
  while (*(a + i)  != 0) {
    ++i;
  }
  int lena = i;

  int j = 0;
  while (*(a + j) != 0) {
    ++j;
  }
  int lenb = i;

  char* a_reversed = malloc(sizeof(char) * lena);
  char* b_reversed = malloc(sizeof(char) * lenb);

  for (int i = lena - 1; i >= 0; --i) {
    a_reversed[lena - (i % lena) - 1] = a[i];
  }
  
  for (int j = lenb - 1; i >= 0; --i) {
    b_reversed[lenb - (i % lenb) - 1] = b[i];
  }


  struct Chars chara;
  struct Chars charb;
  chara.chars = a_reversed;
  chara.len = lena;
  charb.chars = b_reversed;
  charb.len = lenb;
  
  struct Chars chars[] = {chara, charb};
  
  int longerIndex;
  int shorterIndex;
  if (lena > lenb) {
    longerIndex = 0;
    shorterIndex = 1;
  } else {
    longerIndex = 1;
    shorterIndex = 0;
  }
  
  int lenDiff = chars[longerIndex].len - chars[shorterIndex].len;
  char* answer = malloc(sizeof(char) * (lena + lenb));
  int carry = 0;
  char current;
  for (
  int i = chars[longerIndex].len; // Only had to do this because I hadn't reversed the list.
  i >= chars[longerIndex].len - chars[shorterIndex].len - 1;
  --i
  ) {
    if (a[i] == '0' && b[i - lenDiff] == '0') {
      if (carry) {current = '1';}
      carry = 0;
    } else if (
        (a[i] == '0' && b[i - lenDiff] == '1') ||
        (a[i] == '1' && b[i - lenDiff] == '0')
      ) {
      if (carry) {current = '0';}
      carry = 1;
    } else if (a[i] == '1' && b[i - lenDiff] == '1') {
      if (carry) {current = '1';}
      carry = 1;
    }
    answer[i] = current;
  }

  return answer;
}

void main() {
  char* a = "11";
  char* b = "11";
  char* answer = addBinary(a, b);
  for (int i = 0; i < 4; ++i) {
    printf("%c", *(answer + i));
  }
}
