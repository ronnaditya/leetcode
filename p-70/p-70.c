#include<stdio.h>

int climbStairs(int n) {
  int current = 1;
  int previous = 0;
  for (int i = 1; i <= n; ++i) {
    int next = current + previous;
    previous = current;
    current = next;
  }
  return current;
}

void main() {
  printf("%d", climbStairs(9));
}
