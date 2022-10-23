// https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int a, b;
        sort(nums.begin(), nums.end());
        vector<bool>hash(nums.size()+1, false);
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]==nums[i-1])
                a = nums[i];
        }
        for(int i = 0; i<nums.size(); i++){
           hash[nums[i]]=true;
        }
        for(int i = 1; i<=nums.size(); i++)
        {
            if(!hash[i])
                b = i;
        }
        return {a, b};
    }
};