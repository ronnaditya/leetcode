#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct Count {
    int left;
    int right;
};

bool isBalanced(struct TreeNode* root) {
    struct Count* treeTraversal(struct Count* count, struct TreeNode* node) {
        if (node == NULL) {
            return count;
        } else if ((node->right != NULL) && (node->left == NULL)) {
            count->right += treeTraversal(count, node->right)->right;
            count->right += 1;
        } else if ((node->left != NULL) && (node->right == NULL)) {
            count->left += treeTraversal(count, node->left)->left;
            count->left += 1;
        } else {
            count->left += treeTraversal(count, node->left)->left;
            count->right += treeTraversal(count, node->right)->right;
            count->left += 1;
            count->right += 1;
        }
        return count;
    }
    struct Count* count = malloc(sizeof(struct Count));
    count->left = 0;
    count->right = 0;
    count = treeTraversal(count, root);
    printf("%d, %d", count->left, count->right);
    if (abs(count->left - count->right) > 1) {return 0;}
    else {return 1;}
}
