#include<stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
}

int main() {
  struct ListNode l1;
  
  int i = 0;
  while (i < 3) {
    l1.val = i * 3;
    struct ListNode tmp;
    struct ListNode* ptr_tmp = &tmp;
    l1.next = ptr_tmp;
    l1 = *l1.next;
    ++i;
  }

  for (int i = 0; i < 3; ++i) {
    printf("%d", l1.val);
    struct ListNode* ptr_next;
    ptr_next = l1.next;
    l1 = *ptr_next;
  }

  return 0;
}
