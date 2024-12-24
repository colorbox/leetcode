/*
Time : O(NM)
Space : O(NM)

step1と方針は同じだが、セルフレビューで微修正を加えた
*/
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row_count = grid.size();
    int col_count = grid[0].size();
    vector<vector<bool>> visited(row_count, vector<bool>(col_count, false));
    int maximum_island_area = 0;
    for (int row = 0; row < row_count; ++row) {
      for (int col = 0; col < col_count; ++col) {
        if (grid[row][col] == 0 || visited[row][col]) {
          continue;
        }
        int island_area = CountIslandArea(row, col, grid, visited);
        maximum_island_area = max(maximum_island_area, island_area);
      }
    }
    return maximum_island_area;
  }

 private:
 int CountIslandArea(const int start_row, const int start_col, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    stack<pair<int, int>> next_coordinates;
    next_coordinates.emplace(start_row, start_col);
    int area_count = 0;
    while (!next_coordinates.empty()) {
      auto [row, col] = next_coordinates.top();
      next_coordinates.pop();
      if (row < 0 || grid.size() <= row || col < 0 || grid.front().size() <= col) {
        continue;
      }
      if (grid[row][col] == 0) {
        continue;
      }
      if (visited[row][col]) {
        continue;
      }
      visited[row][col] = true;
      ++area_count;
      next_coordinates.emplace(row + 1, col);
      next_coordinates.emplace(row - 1, col);
      next_coordinates.emplace(row, col + 1);
      next_coordinates.emplace(row, col - 1);
    }
    return area_count;
  }
};
