class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 1;
        unordered_map<char, int>mp;
        int i = 0, j = 0;
        while(j<s.length()){
            mp[s[j]]++;
            int cntNalle = 0;
            char imposter;
            for(auto x:mp){
                if(x.second>cntNalle){
                    cntNalle = x.second;
                    imposter = x.first;
                }
            }
            int remain = (j-i+1) - cntNalle;
            if(remain<=k){
                maxLen = max(maxLen, (j-i+1));
            }else{
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return maxLen;
    }
};