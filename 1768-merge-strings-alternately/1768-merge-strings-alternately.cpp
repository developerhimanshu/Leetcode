class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0 , j = 0;
        while(i<word1.length() && j<word2.length()){
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;j++;
        }
        if(i<word1.length()){
            ans+=word1.substr(i);

        }
        if(j<word2.length()){
            ans+=word2.substr(j);
        }
        return ans;
    }
};