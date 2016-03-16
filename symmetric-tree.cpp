class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return sameHelper(root->left, root->right);
    }
    
    bool sameHelper(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        if((!left && right)||(left && !right)||(left->val != right->val)){
            return false;
        }
        return sameHelper(left->right, right->left) && sameHelper(left->left, right->right);
    }
};
