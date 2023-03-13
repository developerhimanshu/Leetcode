//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int s, vector<bool>&vis, vector<bool>&pathVis, vector<vector<int>>&adj){
        vis[s] = true;
        pathVis[s] = true;
        
        for(x:adj[s]){
            if(!vis[x]){
                if(dfs(x, vis, pathVis, adj))return true;
            }
            else if(pathVis[x]){
                return true;
            }
        }
        pathVis[s] = false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj(N);
	    for(auto x:prerequisites){
	        adj[x.first].push_back(x.second);
	    }
	    
	    vector<bool>vis(N, false), pathVis(N, false);
	    for(int i = 0; i<N; i++){
	        if(!vis[i]){
	            if(dfs(i, vis, pathVis, adj))return false;
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends