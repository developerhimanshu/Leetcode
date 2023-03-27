class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int b = prices[0];
        int ind = 1;
        while(ind<prices.size()){
            if(prices[ind]<b){
                b = prices[ind];
            }
            else{
                maxProfit = max(maxProfit, (prices[ind]-b));
            }
            ind++;
        }
        return maxProfit;
    }
};