// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    bool isvowel(char a){
        return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U');
    }
    string reverseVowels(string s) {
        int l = 0, h = s.length();
        while(l<h){
            if(isvowel(s[l])&&isvowel(s[h])){swap(s[l], s[h]);l++;h--;}
            else if(isvowel(s[l]))
                h--;
            else if(isvowel(s[h]))
                l++;
            else
            {
                l++;h--;
            }
        }
        return s;
    }
};