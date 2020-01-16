bool containsDuplicate(vector<int>& nums) {
    map<int, int> intCount;
    for (int i = 0; i < nums.size(); i++) {
        if (++intCount[nums[i]] > 1) {
            return true;
        }
    }
    return false;
}
