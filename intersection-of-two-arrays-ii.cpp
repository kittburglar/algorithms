vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> intCount;
    vector<int> retVal;
    for(int i = 0; i < nums1.size(); i++) {
        intCount[nums1[i]]++;
    }

    for(int i = 0; i < nums2.size(); i++) {
        if (--intCount[nums2[i]] >= 0) {
            retVal.push_back(nums2[i]);
        }
    }

    return retVal;
}
