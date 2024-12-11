/*
Solve Time : 42:17

Time : O(NM log NM)
Space : O(NM)

まずBFSな方法を思いつく。
島を探索し、陸を見つけたら関数を呼び出して陸地すべてを探索済みにしてカウントアップする。
初期値として{0, 0}を設定していたが、そこが島だと適切にカウントされないパターンがあったためすべてのマスをまずキューに入れたらpassした

Set<Coordinate>を利用するうえでoperator<の宣言が必要なことに気づけず時間がかかった。
*/
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int island_count = 0;
    width = grid.front().size();
    height = grid.size();
    queue<Coordinate> checking_coordinates;
    for (int y = 0; y < grid.size(); ++y) {
      for (int x = 0; x < grid.front().size(); ++x) {
        checking_coordinates.push({x, y});
      }
    }
    int count = 0;
    while (!checking_coordinates.empty()) {
      Coordinate coordinate = checking_coordinates.front();
      checking_coordinates.pop();
      if (visited.contains(coordinate)) {
        continue;
      }
      if (grid.at(coordinate.y).at(coordinate.x) == '1') {
        CheckIsland(coordinate, grid);
        ++count;
      }
      visited.insert(coordinate);
      if (coordinate.x - 1 >= 0) checking_coordinates.push({coordinate.x - 1, coordinate.y});
      if (coordinate.x + 1 < width) checking_coordinates.push({coordinate.x + 1, coordinate.y});
      if (coordinate.y - 1 >= 0) checking_coordinates.push({coordinate.x, coordinate.y - 1});
      if (coordinate.y + 1 < height) checking_coordinates.push({coordinate.x, coordinate.y + 1});
    }
    return count;
  }

 private:
  struct Coordinate {
    int x;
    int y;
    bool operator<(const Coordinate& other) const {
      return (y < other.y) || (y == other.y && x < other.x);
    }
  };

  int width;
  int height;
  set<Coordinate> visited;

  void CheckIsland(Coordinate coordinate, const vector<vector<char>>& grid) {
    queue<Coordinate> island_coordinates;
    island_coordinates.push(coordinate);
    while (!island_coordinates.empty()) {
      Coordinate coordinate = island_coordinates.front();
      island_coordinates.pop();
      if (visited.contains(coordinate)) {
        continue;
      }
      visited.insert(coordinate);
      if (grid.at(coordinate.y).at(coordinate.x) == '1') {
        visited.insert(coordinate);
        if (coordinate.x - 1 >= 0) island_coordinates.push({coordinate.x - 1, coordinate.y});
        if (coordinate.x + 1 < width) island_coordinates.push({coordinate.x + 1, coordinate.y});
        if (coordinate.y - 1 >= 0) island_coordinates.push({coordinate.x, coordinate.y - 1});
        if (coordinate.y + 1 < height) island_coordinates.push({coordinate.x, coordinate.y + 1});
      }
    }
  }
};
