class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if(!root){
            return vec;
        }
        binaryTreePathsHelper(vec, "", root);
        return vec;
    }
    
    void binaryTreePathsHelper(vector<string>& vec, string s, TreeNode* root){
        if(!root->left && !root->right){
            s = s + to_string(root->val);
            vec.push_back(s);
            return;
        }
        else{
            
            s = s + to_string(root->val) + "->";
            if(root->left)
                binaryTreePathsHelper(vec, s, root->left);
            if(root->right)
                binaryTreePathsHelper(vec, s, root->right);
        }
        
    }
};
