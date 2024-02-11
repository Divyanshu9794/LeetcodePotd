class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
       
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,0)));
        
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                    dp[m-1][j][k] = grid[m-1][j];
                if(j != k) 
                    dp[m-1][j][k] +=  grid[m-1][k];
            }
        }
        
        
        for(int i = m-2; i >= 0 ; i--){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    int res = 0;
                    res += grid[i][j];
                    if(j != k)
                        res += grid[i][k];
                    int curr = 0;
                    for(int nj = j-1; nj <= j+1; nj++){
                        for(int nk = k-1; nk <= k+1; nk++){
                            if(nj>=0 && nj < n && nk >=0 && nk < n){
                                curr = max(curr,dp[i+1][nj][nk]);
                            }
                        }
                    }
                    res += curr;
                    dp[i][j][k] = res;
                }
            }
        }
        
        return dp[0][0][n-1];
            
    }
};