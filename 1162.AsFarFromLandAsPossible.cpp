class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        vector<vector<int>>visited=grid;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                
                if(visited[i][j])q.push({i, j});
            }
        }
        
        int distance = -1;
        if(q.empty()||q.size()==grid.size()*grid.size())return -1;
        vector<pair<int, int>>dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy]:dirs){
                    int i = x+dx, j = y+dy;
                    if(j>=0 && i>=0&&j<grid.size()&&i<grid.size()&& !visited[i][j])
                    {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};