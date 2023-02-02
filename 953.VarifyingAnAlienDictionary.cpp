class Solution {
public:
    bool isValid(string w1, string w2, vector<int>&hash){
        int i = 0;
        while(w1[i]==w2[i] && i<min(w1.size(), w2.size())){
            i++;
        }
        if(i==w1.size()&&i==w2.size())return true;
        if(i==w1.size()) return true;
        if(i==w2.size())return false;
        return hash[w1[i]-'a'] < hash[w2[i]-'a'];
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>hash(264, 0);
        int itr = 1;
        for(auto x:order){
            hash[x-'a'] = itr;
            itr++;
        }
       
        for(int i = 0; i<words.size(); i++){
            for(int j = i+1;j <words.size(); j++){
                if(!isValid(words[i], words[j], hash))return false;
            }
        }
        return true;
    }
};