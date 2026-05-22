#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* arrayConstructor(int num) {
  int* numArray = malloc(sizeof(int) * 2);

  int count = 0;
  while (num != 0) {
    int current = num % 10;
    numArray[i] = current;
    num /= 10;
    ++count;
  }

  struct ListNode* nodeArray = malloc(sizeof(struct ListNode) * count);
  for (int j = 0; j < count; ++j) {
    if (j == 0) {
      struct ListNode node;
      node.val = numArray[j];
      node.next = NULL;
    } else {
      struct ListNode node;
      node.val = numArray[j];
      
    }
  }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
}

void main() {
  numArray = listConstructor(123123);

}
