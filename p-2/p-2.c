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

int numExtractor(struct ListNode* l) {
  int n = 0;
  int power = 0;
  while (l->next != NULL) {
    n += l->val * (pow(10, power));
    l = l->next;
    ++power;
  }
  n += l->val * pow(10, power);

  return n;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int n1 = numExtractor(l1);
  int n2 = numExtractor(l2);

  
  int n3 = n1 + n2;

  return listConstructor(n3);
}

void main() {
  struct ListNode* l1 = listConstructor(342);
  struct ListNode* l2 = listConstructor(465);

  struct ListNode* l3 = addTwoNumbers(l1, l2);

  printf("%d", numExtractor(l3));

  free(l1);
  free(l2);
  free(l3);
}
