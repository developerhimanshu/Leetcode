class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp;
        if(s1.size()>s2.size())return false;
        for(auto x:s1){
           mp[x]++;
        }
        
        unordered_map<char, int>mp2;
        for(int i = 0; i<s1.size(); i++){
            mp2[s2[i]]++;
        }
        if(mp==mp2)return true;

        // Setting window size
        int p1 = 0, p2 = s1.size();

        //sliding window
        while(p2<s2.size()){
            mp2[s2[p1]]--;
            if(mp2[s2[p1]]==0)mp2.erase(s2[p1]);
            p1++;
            mp2[s2[p2++]]++;
            if(mp==mp2)return true;
        }
        return false;
    }
};