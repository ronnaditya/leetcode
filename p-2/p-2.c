#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* listConstructor(int num) {
  int* numArray = malloc(sizeof(int) * 2);

  int count = 0;
  while (num != 0) {
    int current = num % 10;
    numArray[count] = current;
    num /= 10;
    ++count;
  }

  struct ListNode* nodeArray = malloc(sizeof(struct ListNode) * count);
  struct ListNode* tmpNode;
  for (int j = count - 1; j >= 0; --j) {
    struct ListNode* node;
    if (j == count - 1) {
      node->val = numArray[j];
      node->next = NULL;
      nodeArray[j] = *node;
      tmpNode = node;
    } else {
      node->val = numArray[j];
      node->next = tmpNode;
      nodeArray[j] = *node;
      tmpNode = node;
    }
  }
  return tmpNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
}

void main() {
  struct ListNode* l = listConstructor(123125);

  int i = 0;
  struct ListNode current = *l;
  while (i < 5) {
    printf("%d", current.val);
    current = *current.next;
    ++i;
  }

}
