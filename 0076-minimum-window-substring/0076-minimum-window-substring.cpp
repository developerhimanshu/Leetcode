class Solution {
public:
   
    string minWindow(string s, string t) {
        if(s.length()<t.length())return "";
        map<char, int>mp, window;
        for(auto ch:t)mp[ch]++;
        int have = 0, need = mp.size();
        // cout<<need;
        int i = 0, j = 0;
        int len = INT_MAX, stInd = 0;
        bool flag = false;
        while(j<s.length()){
            if(mp.find(s[j])!= mp.end()){
                if(window[s[j]]>= mp[s[j]]){
                window[s[j]]++;
                }else{
                window[s[j]]++;
                    if(window[s[j]]>= mp[s[j]]){
                        have++;
                    }
                }
            }
            while(have==need){
                flag = true;
                cout<<j<<" "<<i<<endl;
                int currLen = j-i+1;
                if(currLen<len){
                    len = currLen;
                    stInd = i;
                }
                if(mp.find(s[i])!= mp.end()){
                    window[s[i]]--;
                    if(window[s[i]]< mp[s[i]]){
                        // cout<<s[i]<<" "<<i<<endl;
                        have--;
                    }
                }   
                i++;
            }
            j++;
        }
        cout<<len<<" "<<stInd<<endl;
        string ans = "";
        if(!flag)return "";
        for(int i = 0; i<len; i++){
            ans+=s[stInd+i];
        } 
        return ans;
    }
};