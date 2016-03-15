class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>myMap;
        for(int i = 0; i < nums.size(); i++){
            myMap[nums[i]]++;
            if(myMap[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
    }
};
