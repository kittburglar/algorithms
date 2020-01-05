int minDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } 

    int leftDepth = minDepth(root->left), rightDepth = minDepth(root->right);

    if ((root->right != NULL) && (root->left == NULL)) {
        leftDepth = INT_MAX;
    } else if ((root->left != NULL) && (root->right == NULL)) {
        rightDepth = INT_MAX;
    }

    return 1 + min(leftDepth, rightDepth);
}
