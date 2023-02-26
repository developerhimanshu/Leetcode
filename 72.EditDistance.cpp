class Solution {
public:
    int fn(string word1, string word2, int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j]=fn(word1, word2, i-1, j-1, m, n, dp);
        return dp[i][j]=min({1+fn(word1, word2, i-1, j, m, n, dp),1+ fn(word1, word2, i, j-1, m, n, dp), 1+fn(word1, word2, i-1, j-1, m, n, dp)});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        return fn(word1, word2, word1.length()-1, word2.length()-1,word1.length(), word2.length(), dp);
    }
};