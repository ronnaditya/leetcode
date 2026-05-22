#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int size = 3;

  int* ptr_a = malloc(sizeof(int) * 3);
  int* ptr_b = malloc(sizeof(int) * 3);

  for (int i = 0; i < size; ++i) {
    ptr_a[i] = l1->val;
    ptr_b[i] = l2->val;

    l1 = l1->next;
    l2 = l2->next;
  }
  
  int addition[] = {0 , 0, 0};
  bool carried = false;
  for (int i = size - 1; i >= 0; --i) {
    printf("a: %d | b: %d\n", ptr_a[i], ptr_b[i]);
    int current = ptr_a[i] + ptr_b[i];
    if (carried) {
      ++current;
      carried = false;
    }
    if (current >= 10) {
      carried = true;
      current = current % 10;
    }
    addition[i] = current;
  }
  
  for (int i = 0; i < size; ++i) {
    printf("%d", addition[i]);
  }
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

  struct ListNode l21;
  l21.val = 4;
  l21.next = NULL;
  struct ListNode *ptr_l21 = malloc(sizeof(l21));
  ptr_l21 = &l21;
  
  struct ListNode l22;
  l22.val = 6;
  l22.next = ptr_l21;
  struct ListNode *ptr_l22 = malloc(sizeof(l22));
  ptr_l22 = &l22;

  struct ListNode l23;
  l23.val = 5;
  l23.next = ptr_l22;
  struct ListNode *ptr_l23 = malloc(sizeof(l23));
  ptr_l23 = &l23;

 
  addTwoNumbers(ptr_l13, ptr_l23);
}
