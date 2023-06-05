class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        int xdiff=(coordinates[0][0]-coordinates[1][0]);
        int ydiff=(coordinates[0][1]-coordinates[1][1]);
        int currentxdiff,currentydiff;

        for(int i=2;i<n;i++){
            currentxdiff=(coordinates[i-1][0]-coordinates[i][0]);
            currentydiff=(coordinates[i-1][1]-coordinates[i][1]);
            if(ydiff*currentxdiff != xdiff * currentydiff){
                return false;

            }
        }
    return 1;
    }
};
