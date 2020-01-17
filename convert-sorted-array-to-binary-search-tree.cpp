class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int startIndex, int endIndex) {
        if(startIndex > endIndex) {
            return NULL;
        }
        
        int middleIndex = (startIndex + endIndex)/2;
        TreeNode* root = new TreeNode(nums[middleIndex]);
        
        root->left = sortedArrayToBST(nums, startIndex, middleIndex - 1);
        root->right = sortedArrayToBST(nums, middleIndex + 1, endIndex);
        
        return root;
    }
};
