class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeating = -1, missing = -1;
        map<int,int> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[grid[i][j]]++;
            }
        }

        // Check from 1 to n*n
        for(int i=1; i<=n*n; i++){
            if(mp[i] == 0){          // not present
                missing = i;
            }
            else if(mp[i] == 2){     // repeated twice
                repeating = i;
            }
        }

        return {repeating, missing};
    }
};
