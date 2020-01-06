int majorityElement(vector<int>& nums) {
    map<int, int> countMap;

    for (int i = 0; i < nums.size(); i++) {
        if (++countMap[nums[i]] > nums.size()/2) {
            return nums[i];
        }
    }

    return 0;
}
