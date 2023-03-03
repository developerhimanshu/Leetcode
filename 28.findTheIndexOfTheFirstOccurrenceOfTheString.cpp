class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = needle.length();
        int i = 0;
        while(i<haystack.size()){
            string st = haystack.substr(i, l);
            cout<<st<<endl;
            if(st==needle)return i;
            i+=1;
        }
        return  -1;
    }
};