class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int p1 = 0, p2 = 0;
        int ans = 0;
        while(p2<s.length()){
            if(st.find(s[p2])==st.end()){
                st.insert(s[p2]);
                p2++;
                ans = max(ans, (int)st.size());
            }else{
                while(s[p1]!=s[p2]){
                    st.erase(s[p1]);
                    p1++;
                }
                st.erase(s[p1]);
                p1++;
            }
        }
        return ans;
    }
};