class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int length = nums.size();
        int i = 0;
        while(i < length){
            if(nums[i] == val){
                int temp = nums[i];
                nums[i] = nums[length-1];
                nums[length-1] = temp;
                length--;
            }
            else{
                i++;
            }
        }
        return length;
    }
};
