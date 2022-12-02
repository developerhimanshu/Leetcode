class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())return false;
        unordered_set<char>st;
        vector<int>hash1(30), hash2(30);
        for(auto x:word1){
                hash1[x-'a']++;
                st.insert(x);
        }
        for(auto x:word2){
                hash2[x-'a']++;
                if(st.find(x)==st.end())return false;
        }
        sort(hash1.begin(), hash1.end());
        sort(hash2.begin(), hash2.end());
        return hash1==hash2;
    }
};