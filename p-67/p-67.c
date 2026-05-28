#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Chars {
  char* chars;
  int len;
};

char* addBinary(char* a, char* b) {
  int i = 0;
  while (a[i]  != 0) {
    ++i;
  }
  int lena = i;

  int j = 0;
  while (b[j] != 0) {
    ++j;
  }
  int lenb = j;

  char* a_reversed = malloc(sizeof(char) * lena);
  char* b_reversed = malloc(sizeof(char) * lenb);

  for (int i = lena - 1; i >= 0; --i) {
    a_reversed[lena - (i % lena) - 1] = a[i];
  }
  
  for (int j = lenb - 1; j >= 0; --j) {
    b_reversed[lenb - (j % lenb) - 1] = b[j];
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
  
  char* reversed_answer = malloc(sizeof(char) * (lena + lenb));
  int carry = 0;
  char current;
  for (int i = 0; i < chars[shorterIndex].len; ++i) {
    if (*(a_reversed + i) == '0' && *(b_reversed + i) == '0') {
      if (carry) {current = '1'; carry = 0;}
      else {current = '0';}
    } else if (
        (*(a_reversed + i) == '0' && *(b_reversed + i) == '1') ||
        (*(a_reversed + i) == '1' && *(b_reversed + i) == '0')
      ) {
      if (carry) {current = '0'; carry = 1;}
      else {current = '1';}
    } else if (*(a_reversed + i) == '1' && *(b_reversed + i) == '1') {
      if (carry) {current = '1'; carry = 1;}
      else {current = '0'; carry = 1;}
    }
    *(reversed_answer + i) = current;
  }

  for (int i = chars[shorterIndex].len; i < chars[longerIndex].len; ++i) {
    if (*(chars[longerIndex].chars + i) == '0') {
      if (carry) {current = '1'; carry = '0';}
      else {current = '0';}
    } else {
      if (carry) {current = '0';}
      else {current = '1';}
    }
    *(reversed_answer + i) = current;
  }

  char* answer = malloc(sizeof(char) * (chars[longerIndex].len + 1));
  if (carry) {
    *(reversed_answer + chars[longerIndex].len) = '1';
    for (int i = 0; i < chars[longerIndex].len + 1; ++i) {
      *(answer + i) = *(reversed_answer + (chars[longerIndex].len - (i % (chars[longerIndex].len + 1))));
    }
  } else {
      printf("h");
      *(answer + i) = *(reversed_answer + (chars[longerIndex].len - (i % (chars[longerIndex].len))));
  }
  return answer;
}

void main() {
  char* a = "11";
  char* b = "1";
  char* answer = addBinary(a, b);
  for (int i = 0; i < 4; ++i) {
    printf("%c", *(answer + i));
  }
}
