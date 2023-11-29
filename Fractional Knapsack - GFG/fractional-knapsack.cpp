//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool cmp(pair<int, int>&a, pair<int, int>&b){
        return (double)a.first/a.second > (double)b.first/b.second;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int, int>>vec;
        double ans = 0;
        for(int i = 0; i<n; i++){
            vec.push_back({arr[i].value, arr[i].weight});
        }
        sort(vec.begin(), vec.end(),cmp);
        int ind = 0;
        while(ind<n && W>0){
            if(vec[ind].second<=W){
                ans+=vec[ind].first;
                W-=vec[ind].second;
            }
            else{
                ans+=(W*((double)vec[ind].first/vec[ind].second));
                W=0;
            }
            ind++;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends