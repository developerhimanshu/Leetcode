class Solution {
    private:
    int dfs(int s, vector<vector<pair<int, int>>>&adj, vector<bool>&vis){
        vis[s] = true;
        int ans = INT_MAX;
        for(auto [u, w]:adj[s]){
            ans = min(ans, w);
            if(!vis[u])ans = (min(ans, dfs(u, adj, vis)));
        }
        return ans;
    }
public:
   
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto e:roads){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool> vis(n+1, false);
        return dfs(1, adj, vis);
    }
};