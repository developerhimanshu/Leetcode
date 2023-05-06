class Solution {
public:
    int findMaxi(int mini, int l,int h, vector<int>&nums, int target){
        if(nums[l]+nums[h]<=target)return h;
        while(l<h){
            int mid = (l+h)/2;
            if(mini+nums[mid]>target)h = mid - 1;
            else if(mini+nums[mid]<=target&&mini+nums[mid+1]>target)return mid;
            else l = mid+1;
        }
        return h;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size(), mod = 1e9+7;
        vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        for(int i = 0; i<n; i++){
            if(nums[i]+nums[i]>target)return ans;
            int ind = findMaxi(nums[i], i, n-1, nums, target);
            int diff = ind - i;
            int curr = pows[diff];
            ans = (ans+curr)%mod;
        }
        return ans;
    }
};