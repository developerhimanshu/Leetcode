class Solution {
public:
    bool bfs(vector<vector<int>>&adj, int src, vector<bool>&vis){
        queue<int>q;
        vector<int>colour(adj.size(), -1);
        q.push(src);
        colour[src] = 0;
        vis[src] = true;
        while(!q.empty()){
            int node = q.front();
            int color = colour[node];
            q.pop();
            for(auto u:adj[node]){
                if(u==node)return false;
                vis[src] = true;
                if(u && colour[u]==-1){
                    q.push(u);
                    colour[u] = 1-color;
                    vis[u] = true;
                }else if(u){
                    if(colour[u]==color)return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        for(int i = 0; i<graph.size(); i++){
            for(auto n:graph[i]){
                adj[i].push_back(n);
                adj[n].push_back(i);
            }
        }
       vector<bool>vis(graph.size());
       for(int i = 0; i<graph.size(); i++){
           if(!vis[i]){
               if(!bfs(graph, i, vis))
                    return false;
           }
       }
        return true;
    }
};