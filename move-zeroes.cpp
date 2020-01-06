void moveZeroes(vector<int>& nums) {
    int placementIndex = 0;
    for (int index = 0; index < nums.size(); index++) {
        if (nums[index] != 0) {
            nums[placementIndex++] = nums[index];
        }
    }

    for (int index = placementIndex; index < nums.size(); index++) {
        nums[index] = 0;
    }
}
