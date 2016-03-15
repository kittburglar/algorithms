class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> convert;
        convert['I'] = 1;
        convert['V'] = 5;
        convert['X'] = 10;
        convert['L'] = 50;
        convert['C'] = 100;
        convert['D'] = 500;
        convert['M'] = 1000;
        convert[' '] = 0;
        
        int total = 0;
        char lastChar = ' ';
        for(int i = s.size()-1; i >= 0; i--){
            if((s[i] == 'I' && lastChar == 'V')||(s[i] == 'I' && lastChar == 'X')
            ||(s[i] == 'X' && lastChar == 'L')||(s[i] == 'X' && lastChar == 'C')
            ||(s[i] == 'C' && lastChar == 'D')||(s[i] == 'C' && lastChar == 'M')){
                total = total - convert[s[i]];
            }
            else{
                total = total + convert[s[i]];
            }
            lastChar = s[i];
        }
        return total;
    }
};
