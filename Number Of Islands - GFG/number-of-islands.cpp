//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU{
  public:
  vector<int>parent, size;
  DSU(int n){
      parent.resize(n+1),size.resize(n+1, 1);
      for(int i = 0; i<=n; i++)parent[i] = i;
  }
  int findPar(int node){
      if(parent[node]==node)return node;
      return parent[node] = findPar(parent[node]);
  }
  
  void unionBySize(int u, int v){
      int up = findPar(u), vp = findPar(v);
      
      if(up == vp)return;
      
      if(size[up]<size[vp]){
          parent[up] = vp;
          size[vp]+=size[up];
      }
      else{
          parent[vp] = up;
          size[up]+=size[vp];
      }
  }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DSU ds(n*m);
        
        //node = (i*m)+j
        int cnt = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        vector<int>res;
        vector<pair<int, int>>dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for(auto op:operators){
            int r= op[0], c = op[1];
            if(vis[r][c]){
                res.push_back(cnt);
                continue;
            }
            vis[r][c]  = true;
            cnt++;
               
            for(auto d:dirs){
                int nr = d.first+r;
                int nc = d.second+c;
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    if(vis[nr][nc]){
                        int node1 = (r*m)+c;
                        int node2 = (nr*m)+nc;
                        if(ds.findPar(node1)!=ds.findPar(node2)){
                            ds.unionBySize(node1, node2);
                            cnt--;
                        }
                    }
                }
            }
                
            res.push_back(cnt);
            
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends