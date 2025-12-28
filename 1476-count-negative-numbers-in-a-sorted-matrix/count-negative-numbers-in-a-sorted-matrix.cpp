class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    int row=grid.size()-1;
    int col=0;
    int cnt=0;
    while(row>=0 and col<grid[0].size()){
        if(grid[row][col]>=0){
            col++;
        }
        else if(grid[row][col]<0){
            cnt+=grid[0].size()-col;
            row--;
        }
    }
    return cnt;
}
};