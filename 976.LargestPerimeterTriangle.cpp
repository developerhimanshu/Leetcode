//https://leetcode.com/problems/largest-perimeter-triangle/
class Solution {
public:
    int checkArea(int a, int b, int c){
        float s = (a+b+c)/2.0;
        if(s-a<=0||s-b<=0||s-c<=0)
            return 0;
        else return 1;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        for(int i = n; i>=2;i--){
            int a = nums[i], b = nums[i-1], c = nums[i-2];
            if(checkArea(c, b, a))
                return a+b+c;
        }
        return 0;
    }
};