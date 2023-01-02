class Solution {
public:
    // bool isUpper(string word){
    //     for(auto x:word){
    //         if(x>='a'&&x<='z')return false;
    //     }
    //     return true;
    // }
    // bool isLower(string word){
    //     for(auto x:word){
    //         if(x>='A'&&x<='Z')return false;
    //     }
    //     return true;
    // }
    // bool isFirstCap(string word){
    //     if(word[0]>='a'&&word[0]<='z')return false;
    //     for(int i = 1; i<word.length(); i++){
    //         if(word[i]>='A'&&word[i]<='Z')return false;
    //     }
    //     return true;
    // }
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); i++){
            if(isupper(word[1]) != isupper(word[i]) || 
            islower(word[0]) && isupper(word[i])) return false;
        }        
        return true;
    }
};