#include<stdio.h>
#include<math.h>

void testingCasts(float n) {
  int i = (int)1 + n;
  printf("%d", i);
}

void main() {
  testingCasts(1.999);
}
