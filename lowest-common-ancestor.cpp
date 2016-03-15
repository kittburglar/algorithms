class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        
        if ((root->val >= p->val) && (root->val <= q->val)){
            return root;
        }
        else if((root->val < p->val) && (root->val < q->val)){
            lowestCommonAncestor(root->right, p, q);
        }
        else if((root->val > p->val) && (root->val > q->val)){
            lowestCommonAncestor(root->left, p, q);
        }
    }
};
