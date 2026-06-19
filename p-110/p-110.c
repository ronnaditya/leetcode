#include<stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) { // Finally seeing with clarity.
    int treeTraversal(int count, struct TreeNode* node) {
        if (node == NULL) {return 0;}
        count += 1;
        int leftCount = treeTraversal(count, node->left);
        int rightCount = treeTraversal(count, node->right);

        return (leftCount - rightCount);
    }
    return treeTraversal(0, root);
}
