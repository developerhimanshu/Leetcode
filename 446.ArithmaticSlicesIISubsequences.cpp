#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        vector<unordered_map<ll, int>>dp(n);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                long long diff = (long long)nums[i] - (long long)nums[j];
                if(diff<=INT_MIN || diff>=INT_MAX){
                    continue;
                }
                int seqTillNow = 0;
                if(dp[j].find(diff)!= dp[j].end()){
                    seqTillNow = dp[j][diff];
                }
                dp[i][diff] += seqTillNow+1;
                ans += seqTillNow;
            }
        }
        return (int)ans;
    }
};