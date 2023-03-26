class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int>st;
        set<vector<int>>vt;

        for(auto num:arr)st[num]++;
        for(int i = 0; i<n; i++){
            int j = i+1, k = n - 1;
            while(j<k){
                if(arr[j]+arr[k] == (0-arr[i])){
                    vt.insert({arr[i], arr[j], arr[k]});
                    j++;k--;
                }
                else if(arr[j]+arr[k] > (0-arr[i])){
                    k--;
                }
                else if(arr[j]+arr[k] < (0-arr[i])){
                    j++;
                }
            }
           
        }
        vector<vector<int>>ans;
        for(auto s:vt){
            ans.push_back(s);
        }
        return ans;
    }
};