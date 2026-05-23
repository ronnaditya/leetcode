/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail;
    dummy.next = tail;
    
    int smaller;
    while (l1 != NULL || l2 != NULL) {
        if (l1->val < l2->val) {
            smaller = 0;
        } else {
            smaller = 1;
        }
        
        struct ListNode* node = malloc(sizeof(struct ListNode));
        if (!smaller) {
          node->val = l1->val;
          tail->next = node;
          tail = node;
          l1 = l1->next;
        } else {
          node->val = l2->val;
          tail->next = node;
          tail = node;
          l2 = l2->next;

        }
    }
}
