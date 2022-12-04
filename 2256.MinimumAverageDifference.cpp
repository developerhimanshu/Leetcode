class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int sz = n;
        long long sum = 0;
        for(auto x:nums)sum+=x;
        int miniDiff = INT_MAX;
        long long fst = 0;
        for(int i = 0; i<n; i++){
            fst+=nums[i];
            sum -=nums[i];
            sz--;
            int diff;
            if(sz == 0)
                diff  = abs(fst/(i+1));
            else
                diff = abs(fst/(i+1) - sum/sz);
            if(diff <miniDiff){
                miniDiff = diff;
                ans = i;
            }
        }
        return ans;
    }
};