class Solution {
public:
    int count = 0;
    void dfs(int s, int cnt, vector<bool>&vis, vector<vector<int>>&adj){
        vis[s] = true;
        for(auto u:adj[s]){
            if(!vis[u]){
                dfs(u, cnt+1,vis, adj);
            }
        }
        count+=1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int cnt = 0;
        vector<int>countNodes;
        vector<bool>vis(n, false);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, cnt, vis, adj);
                countNodes.push_back(count);
                count = 0;
            }
        }
        if(countNodes.size()<=1)return 0;
        vector<long long>prefixSum(countNodes.size(), 0);
        prefixSum[0] = countNodes[0];
        for(int i = 1; i<prefixSum.size(); i++){
            prefixSum[i] = prefixSum[i-1] + countNodes[i];
        }
        
        long long ans = 0;
        for(int i = countNodes.size()-1; i>=1; i--){
            ans += (prefixSum[i-1]*countNodes[i]);
        }
        return ans;
    }
};