class Solution {
public:
    bool isvowel(char ch){
       return  ch == 'A'||ch=='a'||ch == 'E'||ch=='e'||ch == 'I'||ch=='i'||ch == 'O'||ch=='o'||ch == 'U'||ch=='u';
    }
    bool halvesAreAlike(string s) {
        int cl  = 0, ch = 0;
        int l = 0, h =s.length()-1;
        while(l<h){
            if(isvowel(s[l]))cl++;
            if(isvowel(s[h]))ch++;
            h--;
            l++;
        }
        return cl == ch;
    }
};