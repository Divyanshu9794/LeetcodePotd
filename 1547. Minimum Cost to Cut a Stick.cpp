class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, vector<int>&cuts){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int k=i; k<=j; k++){
            int ans=cuts[j+1]-cuts[i-1]+f(i, k-1, dp, cuts)+f(k+1, j, dp, cuts);
            mini=min(mini, ans);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(m+1, vector<int>(m+1, -1));
        return f(1, m, dp, cuts);
    }
};