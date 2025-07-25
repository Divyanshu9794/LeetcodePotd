class Solution {
public:

    long long f(int i,int status,int remaining_transaction,vector<int> &prices, vector<vector<vector<long long>>>&dp){
        if(remaining_transaction==0){
            return 0;
        }
        if(i==prices.size()-1){
            if(status==0){
            return 0;
            }
            if(status ==1){
                return prices[i];
            }
            return -prices[i];
        }
        if(dp[i][status][remaining_transaction]!=INT_MIN){
            return dp[i][status][remaining_transaction];
        }
        long long ans = INT_MIN;
        ans = max(ans,f(i+1,status,remaining_transaction,prices,dp));
        if(status==0){
            ans= max(ans,-prices[i]+f(i+1,1,remaining_transaction,prices,dp));
            ans = max(ans,prices[i]+f(i+1,2,remaining_transaction,prices,dp));
        }
        else if(status==1){
            ans = max(ans,prices[i]+f(i+1,0,remaining_transaction-1,prices,dp));
        }
        else{
            ans= max(ans,-prices[i]+f(i+1,0,remaining_transaction-1,prices,dp));
        }
        return dp[i][status][remaining_transaction]=ans;
        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(3,vector<long long>(k+1,INT_MIN)));
        return f(0,0,k,prices,dp);
    }
};