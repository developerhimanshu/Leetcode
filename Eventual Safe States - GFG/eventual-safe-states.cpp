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
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool>safeNodes(V, false);
        vector<bool> vis(V, false);
        vector<bool> dfsVis(V, false);
        for(int i = 0; i<V; i++){
            if(!vis[i])
               dfs(i, vis, dfsVis, adj, safeNodes);
            
        }
        vector<int>res;
        for(int i = 0; i<V; i++){
            if(safeNodes[i])res.push_back(i);
        }
        return res;
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