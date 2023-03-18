//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int s, vector<bool>&vis, vector<bool>&dfsVis, vector<int>adj[], vector<bool>&safeNodes){
        vis[s] = true;
        dfsVis[s] = true;
        safeNodes[s] = false;
        for(auto x:adj[s]){
            if(!vis[x]){
                if(dfs(x, vis, dfsVis, adj, safeNodes))return true;
            }
            else if(dfsVis[x])return true;
        }
        safeNodes[s] = true;
        dfsVis[s] = false;
        return false;
    }
    
    void bfs( vector<vector<int>>&adj, int n, vector<int>&ans){
        queue<int>q;
        vector<int>indegree(n, 0);
        
        for(int i = 0; i<n; i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(indegree[i]==0)q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<vector<int>>graph(V);
        for(int i = 0; i<V; i++){
            for(auto x:adj[i]){
                graph[x].push_back(i);
            }
        }
        vector<int>ans;
       bfs(graph, V, ans);
       sort(ans.begin(), ans.end());
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends