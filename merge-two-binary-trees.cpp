TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if ((t1 == NULL) && (t2 == NULL)) {
        return NULL;
    }

    int val1 = 0; 
    int val2 = 0;
    TreeNode* t1Left = NULL;
    TreeNode* t1Right = NULL;
    TreeNode* t2Left = NULL;
    TreeNode* t2Right = NULL;

    if (t1 == NULL) {
        val1 = 0;
    } else {
        val1 = t1->val;
        t1Left = t1->left;
        t1Right = t1->right;
    }

    if (t2 == NULL) {
        val2 = 0;
    } else {
        val2 = t2->val;
        t2Left = t2->left;
        t2Right = t2->right;
    }

    TreeNode *t = new TreeNode(val1 + val2);
    t->left = mergeTrees(t1Left, t2Left);
    t->right = mergeTrees(t1Right, t2Right);

    return t;
}
