void reverseString(vector<char>& s) {
    int startIndex = 0;
    int endIndex = s.size()-1;
    while (startIndex < endIndex) {
        int temp = s[startIndex];
        s[startIndex++] = s[endIndex];
        s[endIndex--] = temp;
    }
    return;
}
