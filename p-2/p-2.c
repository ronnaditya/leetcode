#include<math.h>
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* listConstructor(int num) {
  int* numArray = malloc(sizeof(int) * 10000000);

  int count = 0;
  while (num != 0) {
    int current = num % 10;
    numArray[count] = current;
    num /= 10;
    ++count;
  }
  struct ListNode* ptr_l = malloc(sizeof(struct ListNode) * count);
  struct ListNode* next = NULL;
  for (int i = count - 1; i >= 0; --i) {
    ptr_l[i].val = numArray[i];
    ptr_l[i].next = next;
    next = &ptr_l[i];
  }
  free(numArray);
  return ptr_l;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int n1 = 0;
  int n2 = 0;

  int power1 = 0;
  while (l1->next != NULL) {
    n1 += l1->val * (pow(10, power1));
    l1 = l1->next;
    ++power1;
  }
  n1 += l1->val * pow(10, power1);
  
  int power2 = 0;
  while (l2->next != NULL) {
    n2 += l2->val * pow(10, power2);
    l2 = l2->next;
    power2 += 1;
  }
  n2 += l2->val * pow(10, power2);
  
  int n3 = n1 + n2;

  return listConstructor(n3);
}

void main() {
  struct ListNode* l1 = listConstructor(342);
  struct ListNode* l2 = listConstructor(465);

  struct ListNode* l3 = addTwoNumbers(l1, l2);

  free(l1);
  free(l2);
  free(l3);
}
