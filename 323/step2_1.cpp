/*
Time : O(n)
Space : O(n)

step1に対してセルフレビューで修正を加えた
- 各ノードを参照する事に階層を引き上げる処理を加えた。
- クラスタのトップを表すマジックナンバーを定数化

*/
class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    const int kClusterTop = -1;
    vector<int> nodes = vector<int>(n, kClusterTop);
    for (auto edge : edges) {
      int left = edge.front();
      int right = edge.back();
      while (nodes[right] >= 0) {
        const int previous_right = right;
        right = nodes[right];
        nodes[previous_right] = right;
      }
      while (nodes[left] >= 0) {
        const int previous_left = left;
        left = nodes[left];
        nodes[previous_left] = left;
      }
      if (left == right) {
        continue;
      }
      if (left > right) {
        swap(left, right);
      }
      nodes[right] = left;
    }
    int count = 0;
    for (auto i : nodes) {
      if (i == kClusterTop) {
        count++;
      }
    }
    return count;
  }
};
