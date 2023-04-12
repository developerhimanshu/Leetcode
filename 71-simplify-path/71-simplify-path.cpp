class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string>st;
        string ans = "/";
        for(int i = 0; i<path.length(); i++){
            if(path[i]=='/')continue;
            else{
                string temp = "";
                while(i<n&&path[i]!='/'){
                    temp+=path[i];
                    i++;
                }
                if(temp==".")continue;
                if(temp==".."){
                    if(st.size())
                        st.pop();
                }else
                    st.push(temp);
            }
        }
       vector<string>routes;
       while(st.size()){
           routes.push_back(st.top());
           st.pop();
       }
       reverse(routes.begin(), routes.end());
       for(int i = 0; i<routes.size(); i++){
            if(i==routes.size()-1)
                ans+=(routes[i]);
            else
                ans+=(routes[i]+"/");
       }
       return ans;
    }
};