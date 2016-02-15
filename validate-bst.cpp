class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN - 1L, INT_MAX + 1L);
    }
    
    bool isValidBSTHelper(TreeNode* root, long min, long max){
        if(!root){
            return true;
        }
        if((root->val >= max) || (root->val <= min)){
            return false;
        }
        return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
    }
};
