class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        if(arr.size()==1)return arr[0];
        int l = 0, h = arr.size()-1;
        int n = arr.size();
        if(arr[0]!=arr[1])return arr[0];
        if(arr[n-1]!=arr[n-2])return arr[n-1];
        while(l<=h){
            int mid = h-((h-l)/2);
            cout<<mid<<endl;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
                return arr[mid];
            else if((arr[mid]==arr[mid-1] && mid%2)||(arr[mid]==arr[mid+1] && mid%2==0)){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
          
        }
        return -1;
    }
};