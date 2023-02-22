class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN, h = 0;
        for(auto weight:weights){
            if(weight>l)l = weight;
            h += weight; 
        }

        while(l<h){
            int m = (l+h)/2;
            
           if(findDays(weights, m)<=days)h = m;
            else
                l = m+1;
        }
        return l;
    }

private:
    int findDays(vector<int>&weights, int CurrCapacity){
        int capacity = 0;
        int days = 1;
        for(auto weight:weights){
            if(capacity+weight>CurrCapacity)
            {
                days++;
                capacity = weight;
            }
            else{
                capacity += weight;
            }
        }
        return days;
    }
};