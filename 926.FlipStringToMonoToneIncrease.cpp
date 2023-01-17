class Solution {
public: 
    int minFlipsMonoIncr(string s) {
      vector<int>left(s.length()+1, 0), right(s.length()+1, 0);
      for(int i = 1; i<=s.length(); i++){
          if(s[i-1]=='1')left[i] = 1+left[i-1];
          else left[i] = left[i-1];
      }
      for(int i = s.length()-1; i>=0; i--){
          if(s[i]=='0')right[i] = 1+right[i+1];
          else
            right[i] = right[i+1];
      }
      int res = INT_MAX;
      for(int i = 0; i<=s.length(); i++){
          res = min(res, left[i]+right[i]);
      }
      return res;
    }