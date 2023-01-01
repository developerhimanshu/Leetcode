class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,vector<int>>pi;
        unordered_map<string,vector<int>>si;
        istringstream ss(s);
        vector<string>str;
        string temp;
        while(ss>>temp){
            str.push_back(temp);
        }
        if(pattern.length()!=str.size())return false;
        for(int i = 0; i<pattern.size(); i++){pi[pattern[i]].push_back(i);si[str[i]].push_back(i);}
        for(int i = 0; i<pattern.size(); i++){
            if(pi[pattern[i]]!=si[str[i]])return false;
        }
        return true;
       
    }
};