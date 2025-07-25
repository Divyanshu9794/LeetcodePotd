class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Rolling variables
        int aheadBuy = 0, aheadNotBuy = 0;     // dp[i+1][1], dp[i+1][0]
        int ahead2Buy = 0, ahead2NotBuy = 0;   // dp[i+2][1], dp[i+2][0]

        for(int i = n - 1; i >= 0; i--) {
            int currBuy = max(-prices[i] + aheadNotBuy, aheadBuy);
            int currNotBuy = max(prices[i] + ahead2Buy, aheadNotBuy);

            // shift for next iteration
            ahead2Buy = aheadBuy;
            ahead2NotBuy = aheadNotBuy;
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy; // we start with buy permission on day 0
    }
};
