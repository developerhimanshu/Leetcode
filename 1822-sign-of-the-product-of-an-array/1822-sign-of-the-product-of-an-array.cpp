class Solution {
public:
    int arraySign(vector<int>& nums) {
        int dir = 1;
        for(auto x:nums){
            if(x<0)dir *= -1;
            else if(x>0)dir *= 1;
            else return 0;
        }
        return dir;
    }
};