class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> diff(2,0),same(2,0);
        // for(int i=0;i<n;i++){
        //     int current_remainder = nums[i]%2;
        //     same[current_remainder] = 1+ same[current_remainder];
        //     diff[current_remainder] = max(diff[current_remainder], 1+ diff[1^current_remainder]);
        // }
        // return max({same[0],same[1],diff[0],diff[1]});

        vector<vector<int>> dp(2,vector<int>(2,0));
        int n = nums.size(), ans =0;
        for(int i=0;i<n;i++){
            int current_remainder = nums[i]%2;
            dp[current_remainder][0] = max(dp[current_remainder][0],1+dp[0][current_remainder]);
            dp[current_remainder][1] = max(dp[current_remainder][1],1+dp[1][current_remainder]);
            ans = max({ans,dp[current_remainder][0],dp[current_remainder][1]});
        }

        return ans;
        
        
    }
};