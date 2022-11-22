//	https://leetcode.com/problems/perfect-squares/description/

class Solution {
    int fn(int n, vector<int>&dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int ans = INT_MAX;
        for(int i = 1; i<=sqrt(n); i++){
            ans = min(ans, 1+fn(n-i*i, dp));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return fn(n, dp);
    }
};
    