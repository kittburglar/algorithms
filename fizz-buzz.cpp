vector<string> fizzBuzz(int n) {
    vector<string> retVal(n);
    for (int i = 1; i <= n; i++) {
        string s = "";
        if (!(i % 3)) {
            s += "Fizz";
        }
        if (!(i % 5)) {
            s += "Buzz";
        }
        if (!s.length()) {
            s = to_string(i);
        }
        retVal[i-1] = s;
    }

    return retVal;
}
