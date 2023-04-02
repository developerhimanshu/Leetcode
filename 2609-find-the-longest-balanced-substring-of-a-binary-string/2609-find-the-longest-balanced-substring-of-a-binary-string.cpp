class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, num0 = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='0'){
                bool isZero = true;
                for(int j = i; j<s.length(); j++){
                    if(s[j]=='0' && num0>0 && !isZero){cout<<j<<endl;num0 = 0;break;}
                    if(s[j]=='0')num0++;
                    else if(s[j]=='1'){
                        isZero = false;
                        num0--;
                    }
                    if(num0==0){
                        ans = max(ans, j-i+1);
                        break;
                    }
                }
                num0 = 0;
            }
        }
        return ans;
    }
};