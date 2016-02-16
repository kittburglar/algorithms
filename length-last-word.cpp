class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] != ' '){
                break;
            }
            else{
                length--;
            }
        }
        for(int i = length-1; i >= 0; i--){
            if(s[i] == ' '){
                return length-i-1;
            }
        }
        return length;
    }
};
