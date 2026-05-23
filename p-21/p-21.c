struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    
    int nextNode;
    while (list1 != NULL || list2 != NULL) {
      if (list1 && list2) {
        if (list1->val < list2->val) {
          nextNode = 0;
        } else {
          nextNode = 1;
        }
      } else if (list1) {
        nextNode = 0;
      } else {
        nextNode = 1;
      }

      struct ListNode* node = malloc(sizeof(struct ListNode));
      if (!nextNode) {
        node->val = list1->val;
        node->next = NULL;
        list1 = list1->next;
      } else {
        node->val = list2->val;
        node->next = NULL;
        list2 = list2->next;
      }
      tail->next = node;
      tail = node;
    }
  return dummy.next;
}
