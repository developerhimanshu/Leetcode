class Solution {
public:
    string addBinary(string a, string b) {
       if(b.length()>a.length())swap(a, b);
       while(b.length()<a.length())b = '0'+b;
       int sz = b.size()-1;
       string res = "";
       char c = '0';
    //    cout<<a<< b<<endl;
       while(sz>=0){
           char c1 = a[sz];
           char c2 = b[sz];
           cout<<c1<< ' '<<c2<<c<<endl;
           if(c1 =='1' && c2 == '1'&&c == '1'){res+='1';c = '1';}
           else if(c1=='1'&&c2 =='1'){
               res+='0';
               c = '1';
           }
           else if((c1=='1'||c2=='1')&&c == '1'){
               res += '0';
               c = '1';
           }
           else if((c1=='1'||c2=='1')&&c=='0'){
                res+='1';
           }
            else if((c1=='0'&&c2=='0')&&c=='1'){
                res+='1';
                c='0';
           }
           else{
               res+='0';
               c = '0';
           }
           sz--;
       }
    //    cout<<c<<endl;
       if(c == '1')
            res += '1';
        reverse(res.begin(), res.end());
        return res;

    }
};