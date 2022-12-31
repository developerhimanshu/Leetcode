class Solution {
public:
    int fn(vector<vector<int>>& grid, int i, int j, int s, int ts){
         if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) return 0;
        if(grid[i][j]==2)return s==ts?1:0;
        grid[i][j] = -1;
        int steps = fn(grid, i+1, j, s+1, ts)+fn(grid, i-1, j, s+1, ts)+fn(grid, i, j+1, s+1, ts)+fn(grid, i, j-1, s+1, ts);
        grid[i][j] = 0;
        return steps;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ts=0, r=0, c=0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1){r = i; c = j;}
                if(grid[i][j]!=-1)ts++;
            }
        }
        return fn(grid, r, c, 1, ts);
    }
};