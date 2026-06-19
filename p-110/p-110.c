bool isBalanced(struct TreeNode* root) {
    bool treeTraversal(struct TreeNode* node) {
        if (node == NULL) {return 1;}
        int left = treeTraversal(node->left);
        int right = treeTraversal(node->right);
        return abs(left - right);
    }  
    return treeTraversal(root);
}
