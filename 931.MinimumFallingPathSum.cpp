class Solution {
public:
    int fn(vector<vector<int>>& matrix, int r, int c,  vector<vector<int>>&dp){
        if(r>=matrix.size())return 0;
        if(c>=matrix[0].size()||c<0)return 1e8;
        if(dp[r][c]!=-1)return dp[r][c];
        return dp[r][c] =  matrix[r][c]+min(fn(matrix, r+1, c-1, dp), min(fn(matrix, r+1, c, dp), fn(matrix, r+1, c+1, dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i<matrix[0].size(); i++){
            ans = min(ans, fn(matrix, 0, i, dp));
        }
        return ans;
    }
};