class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> dp(n);
        dp[0]=1;
        int p1=0,p2=0,p3=0;
        for(int i=1;i<n;i++){
            int tom=dp[p1]*2;
            int thm=dp[p2]*3;
            int fim=dp[p3]*5;
            dp[i]=min(tom,min(thm,fim));
            if(dp[i]==tom){
                p1++;
            }
            if(dp[i]==thm){
                p2++;
            }
            if(dp[i]==fim){
                p3++;
            }

        }
        return dp[n-1];

    }
};