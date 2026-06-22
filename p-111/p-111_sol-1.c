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
        if (node->left == NULL && node->right != NULL) {
            return counter(node->right, count + 1);
        } else if (node->left != NULL && node->right == NULL) {
            return counter(node->left, count + 1);
        } else {
            int left = counter(node->left, count + 1);
            int right = counter(node->right, count + 1);
            if (left < right) {
                return left;
            } else {
                return right;
            }
        }
    }
    return counter(root, 1);
}
