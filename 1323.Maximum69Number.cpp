// https://leetcode.com/problems/maximum-69-number/description/

class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int ind = 0, ind6 = -1;
        while(n>0){
            if(n%10==6){
                ind6 = ind;
            }
            ind++;
            n = n/10;
        }
        if(ind6 == -1)return num;
        n=num+3*pow(10, ind6);
        return n;
    }
};