class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string>st;
        string ans;
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

       while(st.size()){
           ans= "/"+st.top()+ans;
           st.pop();
       }
       return ans.length()?ans:"/";
    }
};