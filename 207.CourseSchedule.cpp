class Solution {
public:
    bool solve(int s, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&dfsTemp){
        vis[s] = true;
        dfsTemp[s] = true;
        for(auto x:adj[s]){
            if(!vis[x]){
                vis[x] = true;
                if(solve(x, adj, vis, dfsTemp))return true;
            }
            else if(dfsTemp[x])return true;
        }
        dfsTemp[s] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<bool>vis(numCourses, false), dfsTemp(numCourses, false);
        vector<vector<int>>adj(numCourses);
        for(auto x:pre){
            adj[x[0]].push_back(x[1]);
        }
        for(int i = 0; i<numCourses; i++)
        {
            if(vis[i]==false&&dfsTemp[i]==false)
                if(solve(i, adj, vis, dfsTemp))
                    return false;
        }
        return true;
    }
};