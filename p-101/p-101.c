bool isSymmetric(struct TreeNode* root) {
    bool isMirror(struct TreeNode* left, struct TreeNode* right) {
      if (left == NULL && right == NULL) {
        return 1;
      } else if (left == NULL || right == NULL) {
        return 0;
      } else if (left->val == right->val) {
        return (isMirror(left->right, right->left) && isMirror(left->left, right->right));
      } else {
        return 0;
      }
    }

    if (root == NULL) {
        return 1;
    } else {
        return isMirror(root->left, root->right);
    }
}
