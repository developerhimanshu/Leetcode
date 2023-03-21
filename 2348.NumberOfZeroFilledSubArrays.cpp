class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        long long cnt = 0;
        for(auto x:nums){
            if(x==0)cnt++;
        }
        bool first = false;
        while(j<nums.size()){
            if(!first && nums[j] == 0){
                i = j;
                j = j;
                first = true;
            }
           
            if(first && (nums[j]!=0)){
                first = false;
                long long n = j - i;
                cout<<n<<endl;
                cnt += (n)*(n-1)/2;
            }

            if(first && j == nums.size()-1){
                long long n = j - i+1;
                cout<<n<<endl;
                cnt += (n)*(n-1)/2;
            }
            j++;
        }
        return cnt;
    }
};