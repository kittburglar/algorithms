class Solution {
public:
    int titleToNumber(string s) {
        int total = 0;
        for(int i = 0; i < s.size(); i++){
            int charToInt = s[i] - 'A' + 1;
            total = total + charToInt * pow(26,(s.size() - i - 1));
        }
        return total;
    }
};
