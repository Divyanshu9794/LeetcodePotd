class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        // Initialize the count variable to store the perimeter count
        int count = 0;
        
        // Iterate through each cell in the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If the cell represents land (value is 1)
                if (grid[row][col] == 1) {
                    // Define the four directions to explore: down, right, up, left
                    int delrow[4] = {1, 0, -1, 0};
                    int delcol[4] = {0, 1, 0, -1};
                    // Iterate through each direction
                    for (int i = 0; i < 4; i++) {
                        // Calculate the new row and column based on the direction
                        int newrow = row + delrow[i];
                        int newcol = col + delcol[i];
                        // If the new position is out of bounds or represents water (value is 0)
                        // then it contributes to the perimeter count
                        if (!(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m) || grid[newrow][newcol] == 0) {
                            count++;
                        }
                    }
                }
            }
        }
        // Return the total perimeter count
        return count;
    }
};