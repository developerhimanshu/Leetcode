class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        long long sum = 0;
        for(auto x:piles)pq.push(x);
        while(!pq.empty()&&k){
            int t  = pq.top();
            pq.pop();
            t = t/2+t%2;
            if(t>1)
                pq.push(t);
            else
                sum+=1;
            k--;
        }
        while(!pq.empty()){
            int ele = pq.top();
            pq.pop();
            sum+=ele;
        }
        return sum;
    }
};