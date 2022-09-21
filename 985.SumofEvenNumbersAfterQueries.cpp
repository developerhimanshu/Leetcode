class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        long long eSum = 0;
        for(auto x:nums){
            if(x%2==0){
                eSum+=x;
            }
        }
        for(int i = 0; i<queries.size(); i++){
            int index = queries[i][1];
            int temp = nums[index];
            nums[index]+=queries[i][0];
            if(nums[index]%2==0){
                if(temp%2==0)
                    eSum=eSum-temp;
                eSum+=nums[index];
                cout<<nums[index]<<" "<<index<<endl;
            }
            else if(temp%2==0){
                eSum-=temp;
            }
            
         res.push_back(eSum);
        }
        return res;
    }
};