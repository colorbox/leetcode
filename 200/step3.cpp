class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    height = grid.size();
    width = grid.front().size();
    visited = vector<vector<bool>>(height, vector<bool>(width, false));
    int island_count = 0;
    for (int row = 0; row < height; ++row) {
      for (int col = 0; col < width; ++col) {
        if (grid.at(row).at(col) == sea || visited.at(row).at(col)) {
          continue;
        }
        WalkThroughIsland(row, col, grid);
        ++island_count;
      }
    }
    return island_count;
  }

 private:
  const char sea = '0';
  int height, width;
  vector<vector<bool>> visited;

  struct Coordinate {
    int row;
    int col;
  };

  void WalkThroughIsland(int row, int col, vector<vector<char>>& grid) {
    stack<Coordinate> next_coordinates;
    next_coordinates.emplace(row, col);
    while (!next_coordinates.empty()) {
      Coordinate coordinate = next_coordinates.top();
      next_coordinates.pop();
      if (coordinate.row < 0 || coordinate.row >= height || coordinate.col < 0 || coordinate.col >= width) {
        continue;
      }
      if (grid.at(coordinate.row).at(coordinate.col) == sea || visited.at(coordinate.row).at(coordinate.col)) {
        continue;
      }
      visited.at(coordinate.row).at(coordinate.col) = true;
      next_coordinates.emplace(coordinate.row + 1, coordinate.col);
      next_coordinates.emplace(coordinate.row - 1, coordinate.col);
      next_coordinates.emplace(coordinate.row, coordinate.col + 1);
      next_coordinates.emplace(coordinate.row, coordinate.col - 1);
    }
  }
};
