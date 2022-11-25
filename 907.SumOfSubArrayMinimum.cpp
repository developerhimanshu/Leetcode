class Solution {
public:
   
    int sumSubarrayMins(vector<int>& arr) {
       long long MOD = 1000000007;
       vector<int>ms{-1};
       int n = arr.size();
       long long ans = 0;
       for(long long i = 0; i<=n; i++){
           while(ms.back() != - 1 && (i==n||(arr[i]<=arr[ms.back()]))){
               int j = ms.back();
               ms.pop_back();
               ans =(ans+arr[j]*(i-j)*(j-ms.back()))%MOD;
           }
           ms.push_back(i);
       }
       return ans;
    }
};