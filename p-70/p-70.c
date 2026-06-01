#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n) {
  int ways = 0;
  if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  } else {
    int ways = 0;
    ways += climbStairs(n - 1);
    ways += climbStairs(n - 2);
    return ways;
  }
}

void main() {
  printf("%d", climbStairs(45));
}
