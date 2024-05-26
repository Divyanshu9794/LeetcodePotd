class Solution {
public:
    int mod=1e9+7;
    int studentAttendance(int n,int A,int Llen,vector<vector<vector<int>>> &dp){
        if(A==2 || Llen==3) return 0;
        if(n==0) return 1;
        if(dp[n][A][Llen]!=-1) return dp[n][A][Llen];
        long long int ans=0;
        ans=studentAttendance(n-1,A,0,dp)%mod;
        ans=(ans+studentAttendance(n-1,A+1,0,dp)%mod)%mod;
        ans=(ans+studentAttendance(n-1,A,Llen+1,dp)%mod)%mod;
        return dp[n][A][Llen]=ans;
    }
    int checkRecord(int n){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(4,0)));
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                dp[0][i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int A=1;A>=0;A--){
                for(int Llen=2;Llen>=0;Llen--){
                    long long int ans=0;
                    ans=dp[i-1][A][0]%mod;
                    ans=(ans+dp[i-1][A+1][0]%mod)%mod;
                    ans=(ans+dp[i-1][A][Llen+1]%mod)%mod;
                    dp[i][A][Llen]=ans;
                }
            }
        }
        return dp[n][0][0];
    }
};