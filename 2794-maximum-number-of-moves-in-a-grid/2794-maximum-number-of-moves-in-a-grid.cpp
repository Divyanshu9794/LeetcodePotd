class Solution {
public:
    vector<vector<int>> g;
    int dp[1005][1005];
    int n, m;
    int dfs(int i, int j, int prev){
        if (i < 0 || j < 0 ||i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int val = g[i][j];
        if (val <= prev) return 0;
        return dp[i][j] = 1 + max({dfs(i - 1, j + 1, val), dfs(i, j + 1, val), dfs(i + 1, j + 1, val)});
    }
    int maxMoves(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(i, 0, -1));
        return ans-1;
    }
};
