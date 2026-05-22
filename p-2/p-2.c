#include<stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}

void main() {
  struct ListNode l1;
  struct ListNode l2;

  l1.val = 3;
  l2.val = 4;

  int a[] = {4,2};
  int b[] = {6,5};

  for (int i = 0; i < 2; ++i) {
    struct ListNode l1_tmp;
    struct ListNode l2_tmp;

    l1_tmp.val = a[i];
    l1_tmp.next = &l1;
    l2_tmp.val = b[i];
    l2_tmp.next = &l2;

    l1 = *l1_tmp.next;
    l2 = *l2_tmp.next;

  printf("%d", l1.next->val);
  }
  
}
