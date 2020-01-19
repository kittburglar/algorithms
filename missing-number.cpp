class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> intCount;
        for (int i = 0; i < nums.size(); i++) {
            intCount[nums[i]]++;
        }
        
        for (int i = 0; i <= nums.size(); i++) {
            if (intCount[i] == 0) {
                return i;
            }
        }
        
        return 0;
    }
};
