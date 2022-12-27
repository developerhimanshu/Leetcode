class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>diff(n);
        for(int i = 0; i<n; i++){
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        int ind = 0;
        int count=0;
        while(additionalRocks>0&&ind<n){
            if(additionalRocks>=diff[ind]){
                additionalRocks -= diff[ind++];
                count++;
            }
            else break;

        }
        while(ind<n){
            if(diff[ind++]==0)count++;
        }
        return count;
    }
};