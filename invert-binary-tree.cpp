TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return NULL;
    }

    TreeNode *tempLeft = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tempLeft);

    return root;
}
