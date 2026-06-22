/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int counter(struct TreeNode* node, int count) {
        if (node->left == NULL && node->right == NULL) {
            return count;
        }
        
        int leftCount = count;
        int rightCount = count;
 
        if (node->left != NULL) {
            leftCount = counter(node->left, leftCount + 1);
        }
        if (node->right != NULL) {
            rightCount = counter(node->right, rightCount + 1);
        }


        if (node->left == NULL) {
            return rightCount;
        }

        if (node->right == NULL) {
            return leftCount;
        }

        if (leftCount < rightCount) {
            return leftCount;
        } else {
            return rightCount;
        }
    }

    return counter(root, 1);
}
