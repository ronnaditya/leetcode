#include<stdlib.h>
#include<stdio.h>

struct ListNode {
  long int val;
  struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
  struct ListNode* origin = head;
  while (head != NULL) {
    struct ListNode* current = malloc(sizeof(struct ListNode));
    current = head;
    long int current_value = current->val;
    while (current->next != NULL) {
      if (current->next->val == current_value) {
        current = current->next;
        continue;
      } else {
        break;
      }
    }
    head->next = current->next;
    head = head->next;
  }
  return origin;
}

void main() {
  long int fill = 1122334455566667777;
  
  struct ListNode* head = NULL;
  while (fill >= 1) {
    struct ListNode* current = malloc(sizeof(struct ListNode));
    current->val = fill % 10;
    current->next = head;
    fill = fill / 10;
    head = current;
  }

  struct ListNode* answer = deleteDuplicates(head);
  while (answer != NULL) {
    printf("%ld", answer->val);
    answer = answer->next;
  }  
}
