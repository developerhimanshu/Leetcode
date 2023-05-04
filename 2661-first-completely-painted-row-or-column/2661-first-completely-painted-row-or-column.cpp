class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m  = mat.size(), n = mat[0].size();
        vector<int>rowsfill(m, 0);
        vector<int>colfill(n, 0);

        vector<int>rowIdxMap((m*n)+1);
        vector<int>colIdxMap((m*n)+1);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int val = mat[i][j];
                rowIdxMap[val] = i;
                colIdxMap[val] = j;
            }
        }
        for(int i = 0; i<arr.size(); i++){
            int val = arr[i];
            int r = rowIdxMap[val];
            int c = colIdxMap[val];
            rowsfill[r]++;
            colfill[c]++;
            if(rowsfill[r]==n || colfill[c]==m)return i;
        }
        return -1;
    }
};