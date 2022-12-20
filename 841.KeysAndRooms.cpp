class Solution {
public:
    void dfs(int s, vector<vector<int>>& rooms, vector<bool> &visited){
        visited[s] = true;
        for(auto u:rooms[s]){
            if(!visited[u])
                dfs(u, rooms, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        dfs(0, rooms, visited);
        for(auto x:visited){
            if(!x)return false;
        }
        return true;

    }
};                                