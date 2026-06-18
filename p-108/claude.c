#include<math.h>
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
    struct TreeNode* instantiateNode(int low, int high) {
        if (low > high) {return NULL;}
        int mid = (high + low) / 2;
        struct TreeNode* node = malloc(sizeof(struct TreeNode));
        node->val = nums[mid];
        node->left = instantiateNode(low, mid - 1);
        node->right = instantiateNode(mid + 1, high);
        return node;
    }
    return instantiateNode(0, numsSize - 1);
}
