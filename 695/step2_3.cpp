/*
Time : O()
Space : O(N * M)

ラムダを用いてstackへの要素追加部分のロジックを修正したものt
*/
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    const int row_count = grid.size();
    const int col_count = grid.front().size();
    auto visited = vector<vector<char>>(row_count, vector<char>(col_count, '0'));
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
                      vector<vector<char>>&visited) {
    stack<pair<int, int>> next_coordinates;
    next_coordinates.emplace(row, col);
    int area = 0;

    auto emplace_if_countable = [&grid, &visited, &next_coordinates, row_count, col_count](
        const int row,
        const int col)  {
      if (!(0 <= row && row < row_count && 0 <= col && col < col_count)) {
        return;
      }
      if (grid[row][col] == kSea) {
        return;
      }
      if (visited[row][col] == '1') {
        return;
      }
      next_coordinates.emplace(row, col);
    };

    while (!next_coordinates.empty()) {
      auto [row, col] = next_coordinates.top();
      next_coordinates.pop();
      if (visited[row][col] == '1') {
        continue;
      }
      visited[row][col] = '1';
      ++area;
      emplace_if_countable(row + 1, col);
      emplace_if_countable(row - 1, col);
      emplace_if_countable(row, col + 1);
      emplace_if_countable(row, col - 1);
    }
    return area;
  }
};
