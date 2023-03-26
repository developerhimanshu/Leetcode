class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        while(true)
        {
            if(k==0){
                break;
            }
            int i = 0;
            while(i<numOnes){
                if(k==0)break;
                sum+=1;
                k-=1;
                i++;
            }
            if(k<=0){
                break;
            }
            k-=numZeros;
            if(k<=0)break;
             i = 0;
            while(i<numNegOnes){
                if(k==0)break;
                sum-=1;
                k-=1;
                i++;
            }
        }
            return sum;
        }
};