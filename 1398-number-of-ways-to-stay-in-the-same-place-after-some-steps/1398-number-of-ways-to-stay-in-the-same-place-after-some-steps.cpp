class Solution {
public:
    const int mod=1e9+7;

    int numWays(int steps, int arrLen) {
        int n=min(steps/2+1, arrLen);
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        dp[0][0]=1;
        #pragma unroll
        for(int mv=1; mv<=steps; mv++){
            for(int i=0; i<=n; i++){
                long long ans = dp[(mv-1)&1][i];
                if (i <n-1) ans = (ans+dp[(mv-1)&1][i+1]) % mod;
                if (i>0) ans = (ans+dp[(mv-1)&1][i-1]) % mod;
                dp[mv&1][i] = ans;
            }
        }
        return dp[steps&1][0];
    }
};