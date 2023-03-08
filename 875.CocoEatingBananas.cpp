class Solution {
public:
    bool check(int speed,vector<int>&piles, int h){
        long long cnt = 0;
        for(auto x:piles){
            if(x%speed==0)cnt+=(x/speed);
            else cnt+=(x/speed+1);
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()==1)
        {
            if(piles[0]<=h)return 1;
            if(piles[0]%h==0)return piles[0]/h;
            else return piles[0]/h+1;
        }
        int l = 0, high = 1e9+7;
        int ans = INT_MAX;
        while(l<high){
            int mid = (l+high)/2;
            if(check(mid, piles, h)){
                ans = min(ans,mid);
                high = mid;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};