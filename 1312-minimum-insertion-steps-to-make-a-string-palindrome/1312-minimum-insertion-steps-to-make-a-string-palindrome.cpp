class Solution {
public:
    int solve(int i, int j , string &s, string &t, vector<vector<int>>&dp){

        if(i<0||j<0)return 0;
        if(dp[i][j]>-1)return dp[i][j];
        if(s[i]==t[j])dp[i][j] = 1+solve(i-1, j-1, s, t, dp);
        else 
            dp[i][j] = max(solve(i-1, j, s, t, dp), solve(i, j-1, s, t, dp));
        return dp[i][j];
    }
  
    int minInsertions(string s) {
       int n = s.length();
        string temp = s;
        reverse(temp.begin(), temp.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return n - solve(n-1, n-1, s, temp, dp);
    }
};