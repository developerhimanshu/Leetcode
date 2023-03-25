class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>st;
        for(auto num:nums){
            st.insert(num);
        }
        int len = 1;
        for(int i = 0; i<nums.size(); i++){
            if(st.find(nums[i]-1)==st.end()){
                int num = nums[i];
                while(st.find(num)!=st.end()){
                    num++;
                }
                len = max(len, num-nums[i]);
            }
        }
        return len;
    }
};