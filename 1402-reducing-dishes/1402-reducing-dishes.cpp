class Solution {
public:
    int fn(int ind, int idx, vector<int>&arr, vector<vector<int>>&dp){
        if(ind>=arr.size())return 0;
        if(dp[ind][idx]!=-1)return dp[ind][idx];
        return dp[ind][idx] =  max(arr[ind]*(idx+1)+fn(ind+1,idx+1, arr, dp), fn(ind+1,idx, arr, dp));

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        sort(satisfaction.begin(), satisfaction.end());
        return fn(0, 0, satisfaction, dp);
    }
};