class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjcent_indexes = vector<vector<int>>(n, vector<int>());
    for (auto edge : edges) {
      const int left = edge.front();
      const int right = edge.back();
      adjcent_indexes[left].emplace_back(right);
      adjcent_indexes[right].emplace_back(left);
    }
    set<int> visited;
    int count = 0;
    for (int index = 0; index < n; ++index) {
      if (visited.contains(index)) {
        continue;
      }
      ++count;
      VisitCluster(index, adjcent_indexes, visited);
    }
    return count;
  }

 private:
  void VisitCluster(const int start_index, const vector<vector<int>>& adjacent_indexes, set<int>& visited) {
    stack<int> next_indexes;
    next_indexes.emplace(start_index);
    while (!next_indexes.empty()) {
      const int index = next_indexes.top();
      next_indexes.pop();
      if (visited.contains(index)) {
        continue;
      }
      visited.insert(index);
      for (const int next_index : adjacent_indexes[index]) {
        next_indexes.emplace(next_index);
      }
    }
  }
};
