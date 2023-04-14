class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        string str2="";
        int n = s.length();
        for(int i=n-1; i>=0; i--)
            str2+=s[i];
        // str2 = s;
        cout<<str2<<endl;
        cout<<s<<endl;
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1]==str2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};