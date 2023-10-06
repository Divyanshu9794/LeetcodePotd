class Solution {
public:
    int dp[59][59];
    int integer(vector<int>&v,int n,int i){
        if(i>=v.size()) return 1;
        if(n<=0) return 1;
        if(dp[i][n]!=-1) return dp[i][n];
        if(v[i]<=n){
            return dp[i][n]=max(v[i]*integer(v,n-v[i],0),integer(v,n,i+1));
        }
        else
        return dp[i][n]=integer(v,n,i+1);
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>v;
        for(int i=1;i<n;i++) v.push_back(i);
        return integer(v,n,0);
    }
};