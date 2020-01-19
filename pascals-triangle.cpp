class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> retVal;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for(int col = 0; col <= i; col++) {
                if (col == 0 || col == i) {
                    row.push_back(1);
                } else {
                    row.push_back(retVal[i-1][col-1] + retVal[i-1][col]);
                }
            }
            retVal.push_back(row);
        }
        return retVal;
    }
};
