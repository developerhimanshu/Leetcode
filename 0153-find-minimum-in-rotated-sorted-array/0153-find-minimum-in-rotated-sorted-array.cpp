class Solution {
public:
    int findMin(vector<int>& arr)  {
        int n = arr.size();
        if(n==1)return arr[0];
       if(arr[0] < arr[arr.size()-1])return arr[0];
       int l = 0, h = n-1;
       while(l<=h){
           int mid = l - (l-h)/2;
           if(arr[mid+1]<arr[mid]){
               return arr[mid+1];
           }else if(arr[mid-1]>arr[mid])return arr[mid];
           else if(arr[mid] >= arr[0]) l = mid+1;
           else if(arr[mid]<arr[0])h = mid-1; 
       }
       return -1;
    }
};