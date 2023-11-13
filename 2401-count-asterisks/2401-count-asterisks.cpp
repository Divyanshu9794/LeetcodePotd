class Solution {
public:
    int countAsterisks(string s) {
        int c=0,ig=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|'){
                ig++;
            }
            if(ig%2==0){
                if(s[i]=='*') c++;
            }
        }
        return c;
        
    }
};