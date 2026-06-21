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
        } else {
            int leftCount = count;
            int rightCount = count;
            if (node->left != NULL) {
                leftCount = counter(node->left, leftCount + 1);
            }
            if (node->right != NULL) {
                rightCount = counter(node->right, rightCount + 1);
            }
            printf("Val: %d, Left:%d, Right: %d\n", node->val, leftCount, rightCount);
            if (leftCount > rightCount || leftCount == 1) {
                return rightCount;
            } else if (leftCount < rightCount || rightCount == 1) {
                return leftCount;
            } else {
                return rightCount;
            }
        }
    }
    int count = 1;
    return counter(root, count);
}
