class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);
        return root;
    }
    
    void invertTreeHelper(TreeNode* root){
        if(!root){
            return;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTreeHelper(root->left);
        invertTreeHelper(root->right);
    }
};
