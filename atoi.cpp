class Solution {
public:
    int myAtoi(string str) {
        int sumTotal = 0;
        for(int i = 0; i < str.length(); i++){
            sumTotal = sumTotal + (str[i] - '0') * pow(10,(str.length() - 1 - i));
        }
        return sumTotal;
    }
};
