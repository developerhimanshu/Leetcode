class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int>mp;
        for(int i = 0; i<chars.length(); i++){
            mp[chars[i]] = vals[i];
        }
        int cost = 0,window = 0 ;
        int j = 0;
        while(j<s.length()){
            int currCost = 0;
            if(mp.find(s[j])!=mp.end())currCost = mp[s[j]];
            else{
                currCost = s[j]-'a'+1;
            }
            window+=currCost;
            if(window<0)window = 0;
            if(cost<window){
                cost = window;
            }
            j++;
        }
        return cost;
    }
};