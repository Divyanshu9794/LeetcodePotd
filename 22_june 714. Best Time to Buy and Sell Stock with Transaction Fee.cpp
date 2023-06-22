class Solution {
public:
    int gen(int ind,vector<int>&prices,int buy,int fee,vector<vector<int>>&dp){
        if(ind==prices.size()) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit+=max((-prices[ind]+gen(ind+1,prices,0,fee,dp)),gen(ind+1,prices,1,fee,dp));
        }
        else{
            profit+=max((prices[ind]-fee+gen(ind+1,prices,1,fee,dp)),gen(ind+1,prices,0,fee,dp));
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return gen(0,prices,1,fee,dp);   
    }
};
