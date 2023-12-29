class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        
        vector<int> prev(n+1, INT_MAX), curr(n+1, INT_MAX);
        prev[n] = 0;

        for(int i = 1; i <= d; i++){
            for(int j = n-1; j >= 0; j--){
                int mx = 0;
                for(int k = j; k <= n-i; k++){
                    mx = max(mx, jobDifficulty[k]);
                    curr[j] = min(curr[j], ((prev[k+1] == INT_MAX) ? INT_MAX : mx + prev[k+1]));
                }
            }
            prev = curr; curr = vector<int>(n+1, INT_MAX);
        }
        return prev[0];
    }
};