class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>game(100007, 0);
        vector<bool>isplayed(100007, 0);

        for(auto x:matches){
            game[x[1]]-=1;
            isplayed[x[1]] = true;
            isplayed[x[0]] = true;
        }
     
        vector<int>temp;
        for(int i = 1; i<100007; i++){
            if(isplayed[i]&&game[i] == 0){
                temp.push_back(i);
            }
        }
     
        vector<int>temp2;
        for(int i = 1; i<100007; i++){
            if(isplayed[i]&&game[i] == -1){
                temp2.push_back(i);
            }
        }
        return {temp, temp2};
    }
};