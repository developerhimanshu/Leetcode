class Solution {
public:
    int fn(int ind, int prev, vector<int>& nums, vector<vector<int>>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind][prev+1] != -1)return dp[ind][prev+1];
        int np = fn(ind+1, prev, nums, dp);
        int p = 0;
        if(prev == -1 || nums[ind]>nums[prev]){
            p = 1+fn(ind+1, ind, nums, dp);
        }
        return dp[ind][prev+1] = max(p, np);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return fn(0, -1, nums, dp);
    }
};