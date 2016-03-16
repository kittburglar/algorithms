class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry;
        if(digits.empty()){
            digits.push_back(1);
            return digits;
        }
        for(int i = digits.size()-1; i>=0; i--){
            if(digits[i] != 9){
                digits[i] += 1;
                break;
            }
            else{
                digits[i] = 0;
            }
        }
        if(digits[0] == 0){
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};
