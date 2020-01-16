bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    map<char, int> charCount;
    for (int i = 0; i < s.length(); i++) {
        charCount[s[i]]++;
        charCount[t[i]]--;
    }
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] != 0) {
            return false;
        }
    }

    return true;
}
