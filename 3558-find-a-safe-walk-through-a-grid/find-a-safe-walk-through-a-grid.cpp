#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        q.push({0, 0});
        visited[0][0] = health - grid[0][0];
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newHealth = visited[x][y] - grid[nx][ny];
                    if (newHealth > 0 && newHealth > visited[nx][ny]) {
                        visited[nx][ny] = newHealth;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return visited[m-1][n-1] > 0;
    }
};
