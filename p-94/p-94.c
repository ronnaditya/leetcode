#include<stdlib.h>

int recursiveTraversal(struct TreeNode* current, int* answer, int index) {
    if (current == NULL) {
        return index;
    } else if (current->left == NULL && current->right == NULL) {
        answer[index++] = current->val;
        return index;
    } else if (current->left != NULL && current->right == NULL) {
      index = recursiveTraversal(current->left, answer, index);
      answer[index++] = current->val;
      return index;
    } else if (current->left == NULL && current-> right != NULL) {
        answer[index++] = current->val;
        index = recursiveTraversal(current->right, answer, index);
        return index;
    } else if (current->left != NULL && current->right != NULL) {
        index = recursiveTraversal(current->left, answer, index);
        answer[index++] = current->val;
        index = recursiveTraversal(current->right, answer, index);

        return index;
    }
    return index;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* answer = malloc(sizeof(int) * 100);
    *returnSize = recursiveTraversal(root, answer, 0);
    return answer;
}
