int maxDepth(struct TreeNode* root) {
  int count(int current_count, struct TreeNode* node) {
    if (node == NULL) {
        return current_count;
    } else if (node->left == NULL && node->right != NULL) {
        return count(current_count + 1, node->right);
    } else if (node->right == NULL && node->left != NULL) {
        return count(current_count + 1, node->left);
    } else {
        int count_left = count(current_count + 1, node->left);
        int count_right = count(current_count + 1, node->right);

        if (count_left < count_right) {
            return count_right;
        } else {
            return count_left;
        }
    }
  }

  return count(0, root);   
}
