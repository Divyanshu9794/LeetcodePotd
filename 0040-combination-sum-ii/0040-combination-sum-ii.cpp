using int2 = pair<char, char>;
class Solution {
public:
    int n;
    vector<vector<int>> dp[101][31];
    vector<vector<int>> dfs(int i, int target, vector<int2>& nWm) 
    {
        if (target == 0) 
            return {{}};

        if (i == n || target < 0) 
            return {};
        

        if (!dp[i][target].empty()) 
            return dp[i][target];
        

        auto [x, m] = nWm[i];
        vector<vector<int>> result;
        for (int j = 0; j <= m; j++) {
            vector<vector<int>> combinations = dfs(i+1, target-j*x, nWm);
            int cz=combinations.size();
            for (int k = 0; k <cz; k++) {
                int ckz=combinations[k].size();
                combinations[k].resize(ckz+j);
                fill(combinations[k].begin()+ckz, combinations[k].end(), x);
                result.push_back(combinations[k]);
            }
        }       
        return  dp[i][target] = result;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        char freq[51]={0}, xMax=0;
        for(char x: candidates){
            freq[x]++;
            xMax=max(xMax, x);
        }
    
        vector<int2> nWm;
        for (char x=1; x<=xMax; x++) {
           char f=freq[x];
           f=min((int)f, target/x);
           if (f>0) nWm.push_back({x, f});
        }
        n=nWm.size();

        fill(&dp[0][0], &dp[0][0]+101*31, vector<vector<int>>());
        return dfs(0, target, nWm);
    } 
};