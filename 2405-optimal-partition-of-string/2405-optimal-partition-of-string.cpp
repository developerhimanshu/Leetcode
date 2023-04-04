class Solution {
public:
    int partitionString(string s) {
        int i = 0;
        int count = 1;
        unordered_set<char>st;
        while(i<s.length()){
            if(st.find(s[i])==st.end())st.insert(s[i]);
            else{
                count++;
                st.erase(st.begin(), st.end());
                st.insert(s[i]);
            }
            i++;
        }
        return count;
    }
};