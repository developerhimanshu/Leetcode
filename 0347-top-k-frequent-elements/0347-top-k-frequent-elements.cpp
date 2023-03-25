class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<pair<int, int>>vec;
        vector<int>ans;
        for(auto num:nums){
            mp[num]++;
        }
        
        for(auto m:mp){
            vec.push_back({m.second, m.first});
        }
        sort(vec.begin(), vec.end());
        int ind = vec.size()-1;
        while(k--){
            ans.push_back(vec[ind].second);
            ind--;
        }
        return ans;
    }
};