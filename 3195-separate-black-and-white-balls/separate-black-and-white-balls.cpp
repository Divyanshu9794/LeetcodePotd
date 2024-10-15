class Solution {
public:
    long long minimumSteps(string s) {
        long long  z=0;
        for( auto i : s){
            if(i=='0')z++;
        }
         long long  i=0;
        long long c=0,ans=0;
        while(i<s.size()){
            if(s[i]=='0'){
                ans=ans+i-c;
                c++;
            }
            i++;
        }
        return ans;
    }
};
