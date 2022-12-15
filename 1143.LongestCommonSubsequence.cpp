class Solution {
public:
    int fn(int i, int j, string &s1, string& s2, vector<vector<int>>&dp){
        if(i>=s1.length()||j>=s2.length())return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j] =  1+fn(i+1, j+1, s1, s2, dp);
        else
            return dp[i][j] = max(fn(i+1, j, s1, s2, dp), fn(i, j+1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, -1));

        return fn(0, 0, text1, text2, dp);
    }
};