#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}

void main() {
  int a[] = {3, 4, 2};
  int b[] = {4, 6, 5};

  struct ListNode l11;
  l11.val = 3;
  l11.next = NULL;
  struct ListNode *ptr_l11 = malloc(sizeof(l11));
  ptr_l11 = &l11;
  
  struct ListNode l12;
  l12.val = 4;
  l12.next = ptr_l11;
  struct ListNode *ptr_l12 = malloc(sizeof(l12));
  ptr_l12 = &l12;

  struct ListNode l13;
  l13.val = 2;
  l13.next = ptr_l12;
  struct ListNode *ptr_l13 = malloc(sizeof(l13));
  ptr_l13 = &l13;
}
