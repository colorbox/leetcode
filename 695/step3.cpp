class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    const int row_count = grid.size();
    const int col_count = grid.front().size();
    auto visited = vector<vector<bool>>(row_count, vector<bool>(col_count, false));
    int max_island_area = 0;
    for (int row = 0; row < row_count; ++row) {
      for (int col = 0; col < col_count; ++col) {
        if (grid[row][col] == kSea) {
          continue;
        }
        const int area = CountIslandArea(row, col, row_count, col_count, grid, visited);
        max_island_area = max(max_island_area, area);
      }
    }
    return max_island_area;
  }

 private:
  static constexpr int kSea = 0;

  int CountIslandArea(const int row, const int col, 
                      const int row_count, const int col_count, 
                      const vector<vector<int>>& grid, 
                      vector<vector<bool>>&visited) {
    stack<pair<int, int>> next_coordinates;
    next_coordinates.emplace(row, col);
    int area = 0;
    while (!next_coordinates.empty()) {
      auto [row, col] = next_coordinates.top();
      next_coordinates.pop();
      if (!(0 <= row && row < row_count && 0 <= col && col < col_count)) {
        continue;
      }
      if (grid[row][col] == kSea) {
        continue;
      }
      if (visited[row][col]) {
        continue;
      }
      visited[row][col] = true;
      ++area;
      next_coordinates.emplace(row + 1, col);
      next_coordinates.emplace(row - 1, col);
      next_coordinates.emplace(row, col + 1);
      next_coordinates.emplace(row, col - 1);
    }
    return area;
  }
};
