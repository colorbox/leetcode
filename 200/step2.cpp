/*
Time : O(NM)
Space : O(NM)

他者のコードを読んだうえで改良したコード
- マジックナンバーの廃止
- 訪問済みのマスの管理にsetではなく2次元vectorにしたほうが定数アクセスで早いので修正
- 範囲外の判定を一行にまとめて見やすくする
- 島内探索前の外海の探索は全探索にしてコードをシンプルにする
といった点を改良
*/
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int island_count = 0;
    height = grid.size();
    width = grid.front().size();
    checked = vector<vector<bool>>(height, vector<bool>(width, false));
    for (int row = 0; row < height; ++row) {
      for (int col = 0; col < width; ++col) {
        if (grid.at(row).at(col) == sea || checked.at(row).at(col)) {
          continue;
        }
        WalkThroughIsland(row, col, grid);
        ++island_count;
      }
    }
    return island_count;
  }

 private:
  int height;
  int width;
  vector<vector<bool>> checked;
  const char sea = '0';

  struct Coordinate {
    int col;
    int row;
  };

  void WalkThroughIsland(int row, int col, vector<vector<char>>& grid) {
    stack<Coordinate> target_coordinates;
    target_coordinates.push({col, row});
    while (!target_coordinates.empty()) {
      Coordinate coordinate = target_coordinates.top();
      target_coordinates.pop();
      if (coordinate.col < 0 || width <= coordinate.col || coordinate.row < 0 || height <= coordinate.row) {
        continue;
      }
      if (checked.at(coordinate.row).at(coordinate.col)) {
        continue;
      }
      checked.at(coordinate.row).at(coordinate.col) = true;
      if (grid.at(coordinate.row).at(coordinate.col) == sea) {
        continue;
      }
      target_coordinates.push({coordinate.col + 1, coordinate.row});
      target_coordinates.push({coordinate.col - 1, coordinate.row});
      target_coordinates.push({coordinate.col, coordinate.row + 1});
      target_coordinates.push({coordinate.col, coordinate.row - 1});
    }
  }
};
