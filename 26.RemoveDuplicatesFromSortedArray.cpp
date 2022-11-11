//	 https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            int j=i+1;
            while(j<nums.size()&& nums[j]==nums[i]){
                j++;
            }
            nums.erase(nums.begin()+i+1, nums.begin()+j);;
        }
        return nums.size();
    }
};