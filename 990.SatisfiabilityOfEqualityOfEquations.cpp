// https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
    int uf[26];
    int find(int x){
        return uf[x]==x?x:(uf[x]=find(uf[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i<25; ++i)uf[i]=i;
        
        //Here if we encounter that two variables are equal then we will set their parent same
        for(auto e:equations){
            if(e[1]=='=')uf[find(e[0]-'a')] = find(e[3]-'a');
        }
        
        // if the parent is of the variables is same but they are not equal to each other then in this case we will return false
        for(auto e:equations){
            if(e[1]=='!'&&find(e[0]-'a')==find(e[3]-'a'))return false;
        }
        return true;
    }
};