class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = 0;
        int sum  = 0, ans= 0;
        while(j<k){
            sum+=arr[j];
            j++;
        }
        if(sum/k>=threshold)ans++;
        while(j<arr.size()){
            sum-=arr[i];
            i++;
            sum+=arr[j];
            if(sum/k>=threshold)ans++;
            j++;
        }
        return ans;
    }
};