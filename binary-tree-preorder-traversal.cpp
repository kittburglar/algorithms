class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(!root){
            return vec;
        }
        preorderTraversalHelper(root, vec);
    }
    
    void preorderTraversalHelper(TreeNode* root, vector<int>& vec){
        if(!root){
            return;
        }
        vec.push_back(root->val);
        preorderTraversalHelper(root->left, vec);
        preorderTraversalHelper(root->right, vec);
    }
};
