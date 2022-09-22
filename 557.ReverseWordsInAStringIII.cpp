class Solution {
public:
    string reverseWords(string s) {
        // reverse(s.begin(), s.end());
        string temp="";
        string res="";
        for(int i = 0; i<s.length(); i++){
            if(s[i]==' '||(i==s.length()-1)){
                if(i==s.length()-1){
                    temp.push_back(s[i]);
                    reverse(temp.begin(), temp.end());
                    res+=temp;
                }
                else{
                    reverse(temp.begin(), temp.end());
                    res+=temp;
                    res.push_back(' ');
                }
                temp="";
            }else{
                temp.push_back(s[i]);
            }
        }
        // cout<<s<<endl;
        return res;
    }
};