int rangeSumBST(TreeNode* root, int L, int R) {
    if (root == NULL) {
        return 0;
    }
    
    int leftSide = 0, rightSide = 0, value = 0;
    if ((root->val >= L) && (root->val <= R)) {
        value = root->val;
    }
    if (root->val > L) {
        leftSide = rangeSumBST(root->left, L, R);
    } 
    if (root->val < R) {
        rightSide = rangeSumBST(root->right, L, R);
    } 
    
    return value + leftSide + rightSide;
}
