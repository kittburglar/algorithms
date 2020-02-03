class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1);
        return climbStairs(n, memo);
    }
    
    int climbStairs(int n, vector<int>& memo) {
        if (n == 0)
            return 1;
        else if (n < 0) 
            return 0;
        else if (memo[n]) 
            return memo[n];
        
        memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
        return memo[n];
    }
};
