class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n, 1);
        vector<int>suffix(n, 1);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        int i = 1, j = n-2;
        while(i<n&&j>=0){
            prefix[i] = prefix[i-1]*nums[i];
            suffix[j] = suffix[j+1]*nums[j];
            i++;j--;
        }
        vector<int>ans(n);
        ans[0] = suffix[1];
        ans[n-1] = prefix[n-2];
        i = 1;
        while(i<n-1){
            ans[i] = suffix[i+1]*prefix[i-1];
            i++;
        }
        return ans;
    }
};