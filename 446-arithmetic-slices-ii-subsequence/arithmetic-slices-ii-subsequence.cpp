class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, long long>, int> dp;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                ll diff = (ll)nums[i]-(ll)nums[j];
                dp[{i, diff}]++;
                if(dp.find({j, diff}) != dp.end()){
                    dp[{i, diff}] += dp[{j, diff}];
                    ans+=dp[{j, diff}];
                }
            }
        }
        return ans;
    }
};