//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int jos(vector<int>&v, int n, int k, int ind){
        if(v.size()==1)return v[0];
        ind = (ind+k)%n;
        v.erase(v.begin()+k);
        return jos(v, n, k, ind);
    }
    int josephus(int n, int k)
    {
        int ans = 0, i = 1;
        while(i<=n){
            ans = (ans+k)%i;
            i++;
        }
       return ans+1;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends