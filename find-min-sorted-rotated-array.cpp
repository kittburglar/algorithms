class Solution {
public:
    int findMin(vector<int>& nums) {
        int lastNum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < lastNum){
                return nums[i];
            }
            lastNum = nums[i];
        }
    return nums[0];
    }
};
