// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int hash[26]={false};
        for(auto x:sentence)
            hash[x-'a']=true;
        for(auto x:hash){
            if(!x)return x;
        }
        return true;
    }
};