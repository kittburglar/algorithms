class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }        
        
        int j = 0; int i = 1;
        while(i < nums.size()){
            if(nums[j] != nums[i]){
                j++;
                nums[j] = nums[i];
            }
            i++;
        }
        return j+1;
    }
};
