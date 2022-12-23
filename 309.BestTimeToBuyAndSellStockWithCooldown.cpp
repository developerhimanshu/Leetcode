class Solution {
public:
    int fn(int ind, vector<int>& prices,int buy, vector<vector<int>>&dp){
        if(ind>=prices.size())return 0;
        
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            return dp[ind][buy]= max(-prices[ind]+fn(ind+1, prices, 0, dp), fn(ind+1, prices, 1, dp));
        }else{
            return dp[ind][buy] = max(prices[ind]+fn(ind+2, prices, 1, dp), fn(ind+1, prices, 0, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return fn(0, prices, 1, dp);
    }
};