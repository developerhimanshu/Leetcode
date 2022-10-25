//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        string s2;
        for(auto x:word1)
            for(auto y:x)
                s1.push_back(y);
        for(auto x:word2)
            for(auto y:x)s2.push_back(y);
        return s1==s2;
    }
};