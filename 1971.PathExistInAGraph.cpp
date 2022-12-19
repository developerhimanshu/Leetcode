class Solution {
public:
    void dfs(int s, vector<vector<int>>&adj, vector<bool>&visited){
        visited[s] = true;
        for(auto u:adj[s]){
            if(!visited[u])
                dfs(u, adj, visited);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i = 0; i<edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>visited(n, false);
        dfs(source, adj, visited);
        return visited[destination];

    }
};