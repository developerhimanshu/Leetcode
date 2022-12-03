class Solution {
public:
    static bool cmp(pair<char, int>a, pair<char, int>b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        string ans;
        vector<pair<char, long>>hash(256, {'`', 0});
        for(auto ch : s){
            hash[ch] = {ch, ++hash[ch].second};
        }
   
        sort(hash.begin(), hash.end(),cmp);
        for(int i = 0; i<256; i++){
            if(hash[i].second){
                for(int j = 0; j<hash[i].second; j++){
                    ans.push_back(hash[i].first);
                }
            }
        }
        return ans;
    }
};