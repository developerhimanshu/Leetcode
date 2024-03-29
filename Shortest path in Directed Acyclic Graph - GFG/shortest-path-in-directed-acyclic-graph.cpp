//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void dfs(int s, stack<int>&st, vector<bool>&vis, vector<vector<pair<int, int>>>&adj){
        vis[s] = true;
        for(auto u:adj[s]){
            if(!vis[u.first]){
                dfs(u.first, st, vis, adj);
            }
        }
        st.push(s);
    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        stack<int>st;
        vector<bool>vis(N, false);
        vector<vector<pair<int, int>>>adj(N);
        vector<int>topo;
        // cout<<"here"<<endl;
        for(auto x:edges){
            adj[x[0]].push_back({x[1], x[2]});
        }
        for(int i = 0; i<N; i++){
            if(!vis[i]){
                dfs(i, st, vis, adj);
            }
        }
        
        vector<int>dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            // cout<<node<<" ";
            st.pop();
            int currDis = dist[node];
            for(auto x:adj[node]){
                if(currDis+x.second < dist[x.first])
                    dist[x.first] = currDis+x.second;
            }
        }
        for(int i = 0; i<dist.size(); i++){
            if(dist[i]==1e9)dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends