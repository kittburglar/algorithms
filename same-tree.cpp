class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if((!p && q)||(p && !q)){
            return false;
        }
        if(!p->left && !p->right && !q->left && !q->right){
            if(p->val == q->val){
                return true;
            }
        }
        if(p->val == q->val){
            
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else{
            return false;
        }
    }
};
