class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        if(high%2&&low%2)count =(high-low)/2+low%2;
        else if(high%2)count =(high-low)/2+high%2;
        else if(low%2)count =(high-low)/2+low%2;
        else count = (high-low)/2;
        return count;
    }
};