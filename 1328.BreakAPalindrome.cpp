//https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    bool isPal(string s){
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
            return true;
    }
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)return "";
        string temp = palindrome;
        for(int i = 0; i<palindrome.length(); i++){
            if(palindrome[i]>'a'){
                temp[i]='a';
                if(isPal(temp)==false){
                    // cout<<palindrome<<endl;
                    return temp;    
                }
            }
        }
        palindrome[palindrome.length()-1]++;
        return palindrome;
    }
};