class Solution {
public:
    int fn(int ind, vector<int>&arr,  vector<int>&dp){
        if(ind>=arr.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int p = arr[ind] + fn(ind+2, arr, dp);
        int np = fn(ind+1, arr, dp);
        return dp[ind] = max(p, np);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return fn(0, nums, dp); 
    }
};