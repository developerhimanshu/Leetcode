//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void dfs(int s, vector<bool>&vis, stack<int>&st, vector<vector<int>>&adj){
        vis[s] = true;
        for(auto v:adj[s]){
            if(!vis[v]){
                dfs(v, vis, st, adj);
            }
        }
        st.push(s);
    }
    string findOrder(string dict[], int N, int K) {
        // In this problem we will make a directed graph of the alphabets and then perform topo sort.
        
        vector<vector<int>>adj(K);
        // Firstly making a graph from the dictonary
        for(int i = 0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int p1 = 0, p2 = 0;
            while(p1<s1.length()&&p2 <s2.length()){
                if(s1[p1]!=s2[p2]){
                    adj[s1[p1]-'a'].push_back(s2[p2]-'a');
                    break;
                }
                p1++;p2++;
            }
        }
        // for(auto x:adj){
        //     for(auto nd:x)cout<<nd<<" ";
        //     cout<<endl;
            
        // }
        
        stack<int>st;
        vector<bool>vis(K, false);
        for(int i = 0; i<K; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        
        string ans;
        while(!st.empty()){
            int ch = st.top();
            ans.push_back('a'+ch);
            st.pop();
        }
        // cout<<ans<<endl;
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends