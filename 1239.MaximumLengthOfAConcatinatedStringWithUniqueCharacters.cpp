// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
class Solution {
public:
    int solve(vector<string> &arr,int i,int vis){
        if(i==arr.size()){
            return 0 ;
        }
        int n1 = solve(arr,i+1,vis);
        int n2 = INT_MIN;
        bool flag = 0;
        for(int j = 0;j<arr[i].size();j++){
            if((vis & (1<<(arr[i][j]-'a'))) == (1<<(arr[i][j]-'a'))){
                flag=1;
                break;
            }
            else{
                vis |= (1<<(arr[i][j]-'a'));
            }
        }
        if(flag){
            return n1;
        }
        
        n2 = arr[i].size()+solve(arr,i+1,vis);
        return max(n1,n2);
    }
    int maxLength(vector<string>& arr) {
        return solve(arr,0,0);
        
    }
};