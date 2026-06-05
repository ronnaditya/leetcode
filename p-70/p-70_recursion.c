#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n) {
  if (n <= 2) {
    return n;
  } else {
    int ways = 0;
    ways += climbStairs(n - 1);
    ways += climbStairs(n - 2);
    return ways;
  }
}

void main() {
  printf("%d", climbStairs(3));
}
