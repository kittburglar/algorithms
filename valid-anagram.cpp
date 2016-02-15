class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;
        for(int i = 0; i < s.length(); i++){
            myMap[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            myMap[t[i]]--;
            if(myMap[t[i]] < 0){
                return false;
            }
        }
        for(int i = 0; i < s.length(); i++){
            if(myMap[s[i]] != 0){
                return false;    
            }
        }
        return true;
    }
};
