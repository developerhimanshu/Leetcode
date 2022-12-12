class Solution {
public:
    int fn(int n, vector<int>&dp){
        if(n<=2)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = fn(n-1, dp)+fn(n-2, dp);
    }
    int climbStairs(int n) {

        // tabulation sol
        // if(n<=2)return n;
        // int first = 1, second = 2;
        // for(int i = 3; i<=n; i++){
        //     int temp = first+second;
        //     first = second;
        //     second = temp;
        // }
        // return second;



        vector<int>dp(n+1, -1);
        return fn(n, dp);
    }
};