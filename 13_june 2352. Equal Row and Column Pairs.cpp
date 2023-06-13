
class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        std::unordered_map<std::string, int> rowCounts;
        int count = 0;

        for (const auto& row : grid) {
            std::string key = rowToString(row);
            rowCounts[key]++;
        }

        for (size_t col = 0; col < grid[0].size(); col++) {
            std::vector<int> column(grid.size());
            for (size_t row = 0; row < grid.size(); row++) {
                column[row] = grid[row][col];
            }
            std::string key = rowToString(column);
            count += rowCounts[key];
        }

        return count;
    }

private:
    std::string rowToString(const std::vector<int>& row) {
        std::string str;
        for (const auto& num : row) {
            str += std::to_string(num) + ",";
        }
        return str;
    }
};
