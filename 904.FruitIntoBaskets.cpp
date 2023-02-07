class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mp;
        int s = 0, curr = 0;
        int ans = 0;
        while(curr<fruits.size()){
            mp[fruits[curr]]++;
            if(mp.size()<=2)ans = max(ans, curr-s+1);
            else{
                mp[fruits[s]]--;
                if(mp[fruits[s]]==0)mp.erase(fruits[s]);
                s++;
            }
            curr++;
        }
        return ans;
    }
};