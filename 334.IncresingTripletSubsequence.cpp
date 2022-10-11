//https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int n1 = INT_MAX, n2 = INT_MAX;
        for(auto x:nums){
            if(x<=n1){
                n1 = x;
            }else if(x<=n2){
                n2 = x;
            }else{
                return true;
            }
        }
        return false;
    }
};

//This solution works because no matter at the end we are updating n1 but before if we've found n2 that means there exists an n1 previously thats why this solution is valid