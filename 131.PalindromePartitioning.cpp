class Solution {
public:
    bool isPal(string str, int l, int n){
        while(l<n){
            if(str[l]!=str[n])return false;
            l++;n--;
        }
        return true;
    }
    void solve(int ind, string s,string t1, vector<string>temp, vector<vector<string>>&res){
        if(ind==s.length()){
            res.push_back(temp);
            return;
        }
        for(int i = ind; i<s.length(); i++){
            if(isPal(s, ind, i)){
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, t1, temp, res);
                 temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>dp;
        vector<string>temp;
        solve(0, s, "", temp, res);
        return res;
    }
};