class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k,vector<int>(k,0));
        int n = nums.size(), ans =0;
        for(int i=0;i<n;i++){
            int current_remainder = nums[i]%k;
            for(int prerem=0;prerem<k;prerem++){
                dp[current_remainder][prerem] = max(dp[current_remainder][prerem],1+dp[prerem][current_remainder]);
                ans= max(ans,dp[current_remainder][prerem]);
            }
        }

        return ans;
    }
};