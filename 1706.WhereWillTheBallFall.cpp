class Solution {
public:
    
    void journey(vector<vector<int>>& grid, int ind, vector<int>&res){
        int j = ind-1;
        int i = 0;
        int ans = -1;
        for( i = 0; i<grid.size(); i++){
            if(grid[i][j]==1){
                if(j+1==grid[0].size()||grid[i][j+1]==-1)return ;
                j=j+1;
                ans = j;
            }else{
                if(j-1==-1||grid[i][j-1]==1)return ;
                j=j-1;
                ans = j;
            }
        }
        res[ind-1]=ans;
        // return true;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>res(grid[0].size(), -1);
        for(int i = 0; i<grid[0].size(); i++){
            journey(grid, i+1, res);
        }
        return res;
    }
};