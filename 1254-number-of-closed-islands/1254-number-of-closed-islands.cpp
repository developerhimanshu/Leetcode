class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        if(i<0||j<0||i>=n||j>=m)return;
        if(grid[i][j]||vis[i][j])return;
        cout<<"dfs"<<i<<" "<<j<<endl;
        vis[i][j] = true;
        dfs(i-1, j, m, n, grid, vis);
        dfs(i+1, j, m, n, grid, vis);
        dfs(i, j-1, m, n, grid, vis);
        dfs(i, j+1, m, n, grid, vis);

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    cout<<i<<" "<<j<<endl;
                    if(grid[i][j]==0 && !vis[i][j]){
                        dfs(i, j, m, n, grid, vis);
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    count++;
                    dfs(i, j, m, n, grid, vis);
                }
            }
        }
        return count;
    }
};