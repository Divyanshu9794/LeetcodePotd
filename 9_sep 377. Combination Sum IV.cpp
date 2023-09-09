class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
         vector<unsigned long int>dp(target+1,0);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp[0]=1;
        for(int i = nums[0]; i<=target; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i>=nums[j])
                    dp[i]+=dp[i-nums[j]];
                else
                    break;
            }
        }
        return dp[target];
    }
};
