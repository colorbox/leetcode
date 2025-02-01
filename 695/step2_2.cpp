/*
Time : O(NM)
Space : O(NM)

step1と方針は同じ
他の型にPRを見て修正を加えたもの、差分確認用のコード

海のマジックナンバーを定数とした。
マジックナンバーのままコメントにする事も考えたが、利用箇所がに箇所なので定数としたほうが良いだろうと判断。

関数の定義部分が非常に長くて読みづらくなっていたのでスタイルガイドに従って関数定義の引数表記の改行追加。
https://ttsuki.github.io/styleguide/cppguide.ja.html#Function_Calls

CountIslandArea内の島の中にいる判定を「!(島の中にいる)」とした

*/
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    const int row_count = grid.size();
    const int col_count = grid.front().size();
    int max_area_island = 0;
    auto visited = vector<vector<bool>>(row_count, vector<bool>(col_count, false));
    for (int row = 0; row < row_count; ++row) {
      for (int col = 0; col < col_count; ++col) {
        if (grid[row][col] == kSea || visited[row][col]) {
          continue;
        }
        max_area_island = max(max_area_island, CountIslandArea(row, col, row_count, col_count, grid, visited));
      }
    }
    return max_area_island;
  }

 private:
  static constexpr int kSea = 0;

  int CountIslandArea(const int start_row, const int start_col,
                      const int row_count, const int col_count,
                      const vector<vector<int>>& grid,
                      vector<vector<bool>>& visited) {
    stack<pair<int, int>> next_coordinates;
    next_coordinates.emplace(start_row, start_col);
    int island_area = 0;
    while (!next_coordinates.empty()) {
      auto [row, col] = next_coordinates.top();
      next_coordinates.pop();
      if (!(0 <= row && row < row_count && 0 <= col && col < col_count)) {
        continue;
      }
      if (visited[row][col]) {
        continue;
      }
      if (grid[row][col] == kSea) {
        continue;
      }
      visited[row][col] = true;
      island_area++;
      next_coordinates.emplace(row + 1, col);
      next_coordinates.emplace(row - 1, col);
      next_coordinates.emplace(row, col + 1);
      next_coordinates.emplace(row, col - 1);
    }
    return island_area;
  }
};
