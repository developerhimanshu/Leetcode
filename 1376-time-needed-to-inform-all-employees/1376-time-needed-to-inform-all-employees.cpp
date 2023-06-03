class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i = 0; i<n; i++){
            if(manager[i]!=-1){
            adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int, int>>q;
        q.push({headID, informTime[headID]});
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto t = q.front();
                int node = t.first;
                int time = t.second;
                q.pop();
                for(auto u:adj[node]){
                    if(informTime[u] == 0){
                        ans = max(ans, time);
                    }else{
                        q.push({u, time+informTime[u]});
                    }
                }
            }
        }
        return ans;
    }
};