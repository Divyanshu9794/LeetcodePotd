class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int n1=0,n2=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||           s[i]=='U'){
                n1++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(s[i]=='a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||           s[i]=='U'){
                n2++;
            }
        }
        if(n1==n2){
            return true;
        }
        else{
            return false;
        }
        
    }
};