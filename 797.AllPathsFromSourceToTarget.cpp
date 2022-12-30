class Solution {
public:
    void dfs(int s, vector<vector<int>>& graph, vector<int>&temp, vector<vector<int>>&ans){
        temp.push_back(s);
        if(s == graph.size()-1){
            ans.push_back(temp);
        }
        else{
            for(auto it:graph[s]){
                dfs(it, graph, temp, ans);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0, graph, temp, ans);
        return ans; 
    }
};