//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

class Solution {
    int mod = 1e9+7;
public:
    int fn(int n, int k, int tar, vector<vector<int>>&dp){
        if(tar==0&&n==0)return 1;
        if(n==0 || tar <=0)return 0;
        int ans = 0;
        if(dp[n][tar]!=-1)return dp[n][tar];
        for(int i = 1; i<=k; i++){
            ans=(ans+fn(n-1, k, tar-i, dp)%mod)%mod;
        }
        return dp[n][tar]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(31, vector<int>(1001, -1));
        return fn(n, k, target, dp);
    }
};