class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        unordered_map<char, int>m1;
        for(auto ch:p)m1[ch]++;
        int sz = p.size();
        unordered_map<char, int>m2;
        for(int i = 0; i<sz; i++)m2[s[i]]++;
        if(m2==m1)res.push_back(0);
        m2[s[0]]--;
        if(m2[s[0]]==0)
            m2.erase(s[0]);

	// Now we will side the window

        int l = 1, r = sz;
        while(r<s.size()){
            m2[s[r]]++; 
            if(m1==m2)res.push_back(l);
            m2[s[l]]--;
            if(m2[s[l]]==0)
                m2.erase(s[l]);
            l++;r++;
        }
        return res;
    }
};