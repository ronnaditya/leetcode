/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    bool traveller(struct TreeNode* node, bool left, bool right) {
        if (node->left != NULL && node->right != NULL) {
            left = traveller(node->left, left, right);
            right = traveller(node->right, left, right);
        } else if (node->left == NULL && node->right != NULL) {
            left = false;
            right = traveller(node->right, left, right);
        } else if (node->left != NULL && node->right == NULL) {
            right = false;
            left = traveller(node->left, left, right);
        } else {
            return true;
        }

        if (left && right) {
            return true;
        } else {
            return false;
        }
    }

    return traveller(root, true, true);
}
