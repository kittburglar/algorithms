class Solution {
public:

    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        
        if((root->left == NULL) && (root->right == NULL)){
            if((sum - root->val) != 0){
                return false;
            }
            else{
                return true;
            }
        }
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};
