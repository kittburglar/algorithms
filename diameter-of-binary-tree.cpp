class Solution {
    
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        diameter = max(maxDepth(root->left) + maxDepth(root->right), diameter); //going through center vs subtree diameter
        return diameter;
    }
    
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int diameterThroughRoot = max(leftDepth + rightDepth, diameter);
        diameter = max(diameter, diameterThroughRoot);
        return 1 + max(leftDepth, rightDepth);
    }
};
