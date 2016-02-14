class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        searchInsertHelper(nums, target, 0, nums.size()-1);
    }
    
    int searchInsertHelper(vector<int>& nums, int target, int lower, int upper){
        while(lower <= upper){
            std::cout << target << std::endl;
            if(nums[(upper + lower)/2] < target){
                return searchInsertHelper(nums, target, (upper + lower)/2 + 1,  upper);
            }
            else if(nums[(upper+lower)/2] > target){
                return searchInsertHelper(nums, target, lower, (upper + lower)/2 - 1);
            }
            else{
                return (upper+lower)/2;
            }
        }
        return lower;
    }
};
