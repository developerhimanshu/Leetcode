class Solution {
public:
    int fn(vector<int>& nums, int ind, vector<int>&dp){
        if(ind>=nums.size()-1)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans = 1e5;
        for(int j = 1; j<= nums[ind]; j++){
            ans = min(ans, 1+fn(nums, ind+j, dp));
        }
        return dp[ind] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return fn(nums, 0, dp);
    }
};