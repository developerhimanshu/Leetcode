class Solution {
public:
    int mod = 1e9+7;
    int count(int ind, int zero, int one, vector<int>&dp){
       if(ind<0)return 0;
       if(ind==0)return 1;
       if(dp[ind]!=-1)return dp[ind];
       return dp[ind] = (count(ind-zero,zero, one, dp)%mod + count(ind-one, zero, one, dp)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int res = 0;
        vector<int>dp(high+1, -1);
        for(int i = low; i<=high; i++){
            res = (res%mod+count(i, zero, one, dp))%mod;
        }
        return res;
    }
};