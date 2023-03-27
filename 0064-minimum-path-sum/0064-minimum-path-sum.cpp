class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i<0 || j<0)return 1e8;
        if(i==0 && j == 0){
            return grid[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int top = grid[i][j]+helper(i-1, j, grid, dp);
        int left = grid[i][j]+helper(i, j-1, grid, dp);
        return dp[i][j] = min(top, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>prev(n, 0);
        for(int i = 0; i<m; i++){
            vector<int>curr(n, 0);
            for(int j = 0; j<n; j++){
                if(i==0 && j == 0)curr[j] = grid[0][0];
                else{
                    int top = 1e6;
                    int left = 1e6;
                    if(i>0)top = grid[i][j]+prev[j];
                    if(j>0)left = grid[i][j]+curr[j-1];
                    curr[j] = min(top, left);
                }
            }
             prev = curr;
        }

       return prev[n-1];
    }
};