//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int>dist(n+1, INT_MAX);
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int>parent(n+1);
        for(int i = 1; i<=n; i++)parent[i] = i;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
        pq.push({0, 1});
        dist[1] = 0;
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto itr:adj[node]){
                int currNode = itr.first, currwt = itr.second;
                if(dis+currwt < dist[currNode]){
                    dist[currNode] = dis+itr.second;
                    parent[currNode] = node;
                    pq.push({dis+currwt, currNode});
                }
            }
        }
        if(dist[n] == INT_MAX)return {-1};
        
        vector<int>ans;
        int desti = n;
        // ans.push_back(desti);
        while(parent[desti]!=desti){
            ans.push_back(desti);
            desti = parent[desti];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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