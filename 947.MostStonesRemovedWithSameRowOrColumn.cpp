// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
class Solution {
public:
    vector<int>parent;
    int find(int x){
        return parent[x]==x?x:find(parent[x]);
    }
    int removeStones(vector<vector<int>>& stones) {
       int n = (int)stones.size();
       parent.resize(n+1, 0);
       for(int i = 0; i<=n; i++)parent[i]=i;
       for(int i = 0; i<n; i++){
           for(int j = i+1; j<n; j++){
               if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                   int a = find(i);
                   int b = find(j);
                   if(a!=b)parent[b] = a;               
                }
           }
       }
       int connected = 0;
       for(int i = 0; i<n; i++)connected+=parent[i]==i;
       return n - connected;
    }
};