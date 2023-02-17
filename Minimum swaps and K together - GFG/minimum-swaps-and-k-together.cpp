//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complete the function
       int count = 0;int madar = 0;
       for(int i = 0;i<n;i++){
           if(arr[i]<=k)count++;
       }
       for(int i = 0;i<count;i++){
           if(arr[i]>k)madar++;
       }
       int i = 0,j=count;int minswap = INT_MAX;
       minswap = min(madar,minswap);
       for(i,j;i<n && j<n;i++,j++){
           if(arr[i]>k)madar--;
           if(arr[j]>k)madar++;
           minswap = min(madar,minswap);
       }
        return minswap;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends