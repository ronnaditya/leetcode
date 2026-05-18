#include<stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int arr1[3];
  int arr2[3];

  for (int i = 0; i < 3; ++i) {
    arr1[i] = l1->val;
    arr2[i] = l2->val;

    l1 = l1->next;
    l2 = l2->next;
  };
}

int main() {
  struct ListNode l1;
//  struct ListNode l2;

  for (int i = 1; i < 4; ++i) {
    l1.val = i * 3;
    struct ListNode l_next;
    struct ListNode* ptr_l = &l_next;
    l1.next = ptr_l;
    l1 = *ptr_l;
  }
//
//  for (int i = 1; i < 4; ++i) {
//    l2.val = i * 4;
//    struct ListNode* l2_next;
//    l2.next = l2_next;
//    l2 = *l2.next;
//  }

  for (int i = 0; i < 3; ++i) {
    printf("%d", l1.val);
  }

  return 0;
}
