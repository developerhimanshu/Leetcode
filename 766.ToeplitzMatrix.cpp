// https://leetcode.com/problems/toeplitz-matrix/description/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        cout<<m<<n<<endl;
       for(int i = 0; i<n; i++){
           int j = 0;
           int temp = i;
           while(i<n && j <m){
               if(matrix[j][i]!=matrix[0][temp])return false;
               j++;i++; 
           }
           i = temp;
       }
        for(int i = 1; i<m; i++){
           int j = 0;
           int temp = i;
           while(i<m && j <n){
               if(matrix[i][j]!=matrix[temp][0])return false;
               j++;i++; 
           }
           i = temp;
       }
       return true;
    }
};