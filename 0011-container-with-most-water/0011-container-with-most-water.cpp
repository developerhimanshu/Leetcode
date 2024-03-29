class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size()-1;
        int ans = 0;
        while(p1<p2){
            int area = min(height[p1], height[p2])*(p2-p1);
            ans = max(ans, area);
            if(height[p1]<height[p2])p1++;
            else if(height[p1]==height[p2]){
                p1++;p2--;
            }
            else{
                p2--;
            }
        }
        return ans;
    }
};