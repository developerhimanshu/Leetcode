// The concept that is in this problem is, choose a node as a base subtract all the nodes which are linked with it from the base the store them to a list and then store that list to a set

class Solution {
  public:
    vector<int>dx = {0, -1, 0, 1};
    vector<int>dy = {-1, 0, 1, 0};
    
    void dfs(int row, int col,int ir, int ic, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>&vec){
        vis[row][col] = true;
        vec.push_back({row-ir, col-ic});
        for(int i = 0; i<4; i++){
            int nr = row+dx[i];
            int nc = col + dy[i];
            
            if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&!vis[nr][nc]&&grid[nr][nc])
                dfs(nr, nc,ir, ic, grid, vis, vec);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
       set<vector<pair<int, int>>>st;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j]&&grid[i][j]){
                    vector<pair<int, int>>vec;
                    dfs(i, j,i, j, grid, vis, vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};