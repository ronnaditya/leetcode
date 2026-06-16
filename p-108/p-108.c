#include<stdlib.h>
#include<stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int totalCount = 0;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    if (numsSize == 0) {
        return root;
    }

    void constructNode(int count, struct TreeNode* node) {
        if (count < numsSize) {
            struct TreeNode* left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            struct TreeNode* right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->val = nums[count];
            node->left = left;
            node->right = right;
            left->left = NULL;
            left->right = NULL;
            right->left = NULL;
            right->right = NULL;

            totalCount += 1;

            constructNode(totalCount * 2 + 1, node->left);
            constructNode(totalCount * 2 + 2, node->right);
        } else {
            return;
        }
    }
    constructNode(totalCount, root);
    return root;
}
