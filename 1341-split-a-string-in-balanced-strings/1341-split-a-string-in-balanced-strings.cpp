class Solution {
public:
    int balancedStringSplit(string s) {
        int c=0,lc=0,rc=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                lc++;
            }
            else{
                rc++;
            }
            if(lc==rc){
                c++;
            }
        }
        return c;
       
        
    }
};