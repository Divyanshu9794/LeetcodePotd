class Solution {
public:
    int maxPower(string s) {
        int n= s.size();
        int c=1,ans=1;
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                c++;
            }
            else{
                ans = max(ans,c);
                c=1;
            }
        }
        ans =max(c,ans);
        return ans;
    }
};