class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>ans;
        for(int i = 0; i<spells.size(); i++){
            int low = 0, high = potions.size()-1;
            int mid = 0;
            int bestInd = potions.size();
            while(low<=high){
                mid = low - (low - high)/2;
                if(((long long)spells[i]*potions[mid] >= success) &&(mid==0|| (long long)spells[i]*potions[mid-1]<success)){
                    bestInd = mid;
                    break;
                }
                else if((long long)spells[i]*potions[mid] >= success)high = mid-1;
                else if((long long)spells[i]*potions[mid] < success){
                    low = mid+1;
                }
            }
            ans.push_back(potions.size()-bestInd);
        }
        return ans;
    }
};