class Solution {
public:
    int getMax(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(getMax(root->left), getMax(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        
        int diff = (getMax(root->left) - getMax(root->right));
        std::cout << getMax(root->left) << " " << getMax(root->right) << std::endl;
        if((diff > 1) || (diff < -1)){
            return false;
        }
        else{
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
