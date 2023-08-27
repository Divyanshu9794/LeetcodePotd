class Solution {
public:
      bool s(map<int, int> &mp, vector<int>& stones, int last, int k, vector<vector<int>> &dp){
        int num = stones[last] + k;
        if(num == stones.back()) return true;
        if(mp.find(num) == mp.end()) return false;

        if(dp[last][k] != -1) return dp[last][k];

        int idx = mp[num];
        bool ans;

        ans = s(mp, stones, idx, k+1, dp);
        ans = ans || s(mp, stones, idx, k, dp);
        if(k > 1){
            ans = ans || s(mp, stones, idx, k-1, dp);
        }

        return dp[last][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        map<int, int> mp;
        for(int i=0; i<stones.size(); i++){
            mp[stones[i]] = i;
        }

        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        return s(mp, stones, 0, 1, dp);
    }
};
