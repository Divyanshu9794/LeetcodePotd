class Solution {
public:
int solve(int i,int buy,int cap,int n,vector<int> &a,vector<vector<vector<int>>> &dp){
    if(i==n or cap==0) return 0;
    if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    if(buy==1){
        return dp[i][buy][cap]=max(-a[i]+solve(i+1,0,cap,n,a,dp),0+solve(i+1,1,cap,n,a,dp));
    }
    else{
        return dp[i][buy][cap]=max(a[i]+solve(i+1,1,cap-1,n,a,dp),solve(i+1,0,cap,n,a,dp));
    }
}
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
     return solve(0,1,2,n,price,dp);
}
};
