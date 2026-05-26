#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
  int* returnArray = malloc(sizeof(int) * (digitsSize + 1));
  int current;
  int carry = 0;
  for (int i = digitsSize - 1; i >= 0; --i) {
    if (i == digitsSize - 1) {
      current = digits[i] + 1;
    } else {
      current = digits[i] + carry;
      carry = 0;
    }
    if (current >= 10) {
      carry = 1;
      current = current % 10;
    }
    returnArray[i] = current;
  }
  *returnSize = digitsSize;
  if (carry) {
    for (int i = digitsSize - 1; i >= 0; --i) {
      returnArray[i + 1] = returnArray[i];
    }
    returnArray[0] = 1;
    *returnSize += 1;
  }
  return returnArray;
}

void main() {
  int digits[] = {1,2,3};
  int digitsSize = 3;
  int returnSize = 3;
  int* numArray = plusOne(digits, digitsSize, &returnSize);

  for (int i = 0; i < returnSize + 1; ++i) {
    printf("%d\n", numArray[i]);
  }
}
