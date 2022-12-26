class Solution {
public:
    bool fn(vector<int> nums, int ind){
        if(ind == nums.size()-1)return true;
        if(ind >= nums.size())return false;

        bool flag = false;
        for(int i = 1; i<=nums[ind]; i++){
            flag = flag||fn(nums, ind+i);
        }
        return flag;
    }
    bool canJump(vector<int>& nums) {
        // vector<bool>dp(nums.size(), false);
        int n = nums.size();
        // dp[n-1] = true;

        /*
        for(int i = n-2; i>=0; i--){
            for(int j = 1; j<=nums[i] and j+i <n; j++){
                if(dp[i+j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
        */
        int last = n-1;
         for(int i = n-2; i>=0; i--){
            if(i+nums[i]>=last)last = i;
        }
        return last == 0;
    }
};