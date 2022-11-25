class Solution {
public:
    vector<int>rows = {0, -1, 0, 1};
    vector<int>cols = {-1, 0, 1, 0};
    void dfs(int row, int col, vector<vector<char>>&mat, vector<vector<int>>&visited){
        visited[row][col] = 1;
        
        for(int i = 0; i<=3; i++){
            int nr = row + rows[i];
            int nc = col + cols[i];
            if(nr>=0&&nr<mat.size()&&nr>=0&&nc<mat[0].size()&&!visited[nr][nc]&&mat[nr][nc]=='O'){
                dfs(nr, nc, mat, visited);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int j = 0; j<m; j++){
            if(!visited[0][j] && mat[0][j]=='O')
                dfs(0, j, mat, visited);
            if(!visited[n-1][j] && mat[n-1][j]=='O')
                dfs(n-1, j, mat, visited);
        }
        for(int i = 0; i<n; i++){
            if(!visited[i][0] && mat[i][0]=='O')
                dfs(i, 0, mat, visited);
            if(!visited[i][m-1] && mat[i][m-1]=='O')
                dfs(i, m-1, mat, visited);
        }
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j]&&mat[i][j]=='O')
                    mat[i][j] = 'X';
            }
        }
    }
};