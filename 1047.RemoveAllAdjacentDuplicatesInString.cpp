class Solution {
public:
    string removeDuplicates(string s) {
        int st = 0;

        while(st!=s.length()-1){
            if(s[st]==s[st+1]){
                s.erase(st, 2);
                if(st)
                    st--;
            }else
                st++;
        }
        return s;
    }
};