class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int>mp;
        mp["I"]=1;
        mp["V"]=5;
        mp["IV"]=4;
        mp["IX"]=9;
        mp["X"]=10;
        mp["XL"]=40;
        mp["XC"]=90;
        mp["CD"]=400;
        mp["CM"]=900;
        mp["L"]=50;
        mp["C"]=100;
        mp["D"]=500;
        mp["M"]=1000;
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
          if(i!=s.length()-1 )
          {
              string str;
              str.push_back(s[i]);
              str.push_back(s[i+1]);
              if(mp.find(str)!=mp.end()){
              ans+=mp[str];
              i++;}
              else{
              string str;
              str.push_back(s[i]);
            ans+=mp[str];}
          }      
          else{
              string str;
              str.push_back(s[i]);
            ans+=mp[str];}
        }
        return ans;
    }
};