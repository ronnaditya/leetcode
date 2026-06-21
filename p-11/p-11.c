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
        if (node != NULL) {
            count += 1;
            if (node->left == NULL || node->right == NULL) {
                return count;
            } else {
                int leftCount = counter(node->left, count);
                int rightCount = counter(node->right, count);
                if (leftCount > rightCount) {
                    return rightCount;
                } else {
                    return leftCount;
                }
            }
        } else {
            return count;
        }
    }

    int count = 0;

    count = counter(root, count);

    return count;
}
