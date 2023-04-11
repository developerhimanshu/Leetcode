class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto ch:s){
            if(ch=='*'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string res = "";
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};