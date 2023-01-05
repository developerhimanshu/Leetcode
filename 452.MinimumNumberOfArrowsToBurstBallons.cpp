class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int prevBound = points[0][1];
        int count = 1;
        for(int i = 1; i<points.size(); i++){
            if(points[i][0]>prevBound){
                count++;
                prevBound = points[i][1];
            }
        }
        return count;
    }
};