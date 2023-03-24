class Solution {
public:
    int cnt = 0;
    void dfs(int s,vector<vector<int>>&adj, vector<vector<int>>&adj2, vector<bool>&vis){
        vis[s] = true;
        for(auto u:adj[s]){
            if(!vis[u]){
                for(auto v:adj2[s]){
                    if(v==u)cnt++;
                }
            dfs(u, adj, adj2, vis);
            }
            
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<vector<int>>adj2(n);
        vector<bool>vis(n, false);
        for(auto c:connections){
            adj2[c[0]].push_back(c[1]);
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        dfs(0, adj, adj2, vis);
        return cnt;
    }
};