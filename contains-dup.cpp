class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++){
            myMap[nums[i]]++;
            if(myMap[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};
