//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<int>dx={-1, 0, 1, 0};
    vector<int>dy={0, -1, 0, 1};
  public:
    void dfs(int br, int bc, int r, int c,vector<vector<bool>>&visited, vector<pair<int, int>>&v, vector<vector<int>>& grid){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||visited[r][c]||grid[r][c]==0)return;
        visited[r][c] = true;
        v.push_back({br-r, bc-c});
        for(int i = 0; i<4; i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            dfs(br, bc, nr, nc, visited, v, grid);
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
       set<vector<pair<int, int>>>st;
       
       vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(),false));
       for(int i = 0; i<grid.size(); i++){
           for(int j = 0; j<grid[0].size(); j++){
               if(!visited[i][j] && grid[i][j]){
                   vector<pair<int, int>>v;
                   dfs(i, j, i, j, visited, v, grid);
                   st.insert(v);
               }
           }
       }
       return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends