//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dist(n, vector<int>(m, 1e6));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        dist[source.first][source.second] = 0;
        pq.push({0, {source.first, source.second}});
        
        while(!pq.empty()){
            auto x = pq.top();
            int currx = x.second.first;
            int curry = x.second.second;
            int dis = x.first;
            pq.pop();
            
            vector<pair<int, int>>dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
            for(auto d:dir){
                int r = currx+d.first;
                int c = curry+d.second;
                if(r>=0&&r<n&&c>=0&&c<m&&grid[r][c]==1 && dist[r][c]> dis+1){
                    dist[r][c] = 1+dis;
                    pq.push({1+dis, {r, c}});
                }
            }
        }
        return dist[destination.first][destination.second]==1e6?-1:dist[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends