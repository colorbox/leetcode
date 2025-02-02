/*
Time : O(N + M)
Space : O(N + M)

edges.size() = M

他の人の解法を参考にDFSを用いて解き直した。
edge list形式でDFSをするというのが初見でしっくりこなかったが、隣接リスト形式に変換してからDFSするという点はしっくりきた。
自明にデータ形式を変換する考察が不足しており、素直な解法にたどり着けなかったのでその点を補いたい。

*/
class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjacency_nodes = vector<vector<int>>(n, vector<int>());
    vector<char> visited = vector<char>(n, '0');
    for (auto edge : edges) {
      const int x = edge.front();
      const int y = edge.back();
      adjacency_nodes[x].push_back(y);
      adjacency_nodes[y].push_back(x);
    }
    int count = 0;
    for (int index = 0; index < n; ++index) {
      if (visited[index] == '1') {
        continue;
      }
      InvestigateIndexes(index, adjacency_nodes, visited);
      ++count;
    }
    return count;
  }

 private:
  void InvestigateIndexes(int start_index,
                          const vector<vector<int>>& adjacency_nodes,
                          vector<char>& visited) {
    stack<int> next_indexes;
    next_indexes.emplace(start_index);
    while (!next_indexes.empty()) {
      const int index = next_indexes.top();
      next_indexes.pop();
      if (visited[index] == '1') {
        continue;
      }
      visited[index] = '1';
      for (int adjcent_index : adjacency_nodes[index]) {
        if (visited[adjcent_index] == '1') {
          continue;
        }
        next_indexes.emplace(adjcent_index);
      }
    }
  }
};
