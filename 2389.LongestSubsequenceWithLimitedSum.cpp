class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int>prefix(nums.size(), 0);
        prefix[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>ans(queries.size(), 0);
        int j;
        for(int i=0; i<queries.size(); i++){
            j=0;
            for(j = 0; j < nums.size(); j++){
                if(prefix[j]>queries[i])
                    break;
            }
            if(j!=0)
                ans[i]=(j);
        }
        return ans;
    }
};