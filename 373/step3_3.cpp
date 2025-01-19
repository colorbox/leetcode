/*
{i + 1, j}と{i, j + 1}をpriority_queueにいれる時に、{i + 1, j - 1}と{i - 1, j + 1}がvisitedに含まれているかを確認して効率化するパターン
条件判定部分が無駄に複雑なので関数化したいが、いい感じにできないのでそのままにしている
*/
class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<SumIndex, vector<SumIndex>, greater<SumIndex>> sum_index;
    vector<vector<int>> minimum_k_pair;
    set<vector<int>> visited;
    sum_index.push({nums1[0] + nums2[0], 0, 0});
    while (minimum_k_pair.size() < k && sum_index.size() > 0) {
      int i = sum_index.top().num1_index;
      int j = sum_index.top().num2_index;
      sum_index.pop();
      minimum_k_pair.push_back({nums1[i], nums2[j]});
      if (i + 1 < nums1.size() && !visited.contains({i + 1, j}) && (j == 0 || visited.contains({i + 1, j - 1}))) {
        sum_index.push({nums1[i + 1] + nums2[j], i + 1, j});
        visited.insert({i + 1, j});
      }
      if (j + 1 < nums2.size() && !visited.contains({i, j + 1}) && (i == 0 || visited.contains({i - 1, j + 1}))) {
        sum_index.push({nums1[i] + nums2[j + 1], i, j + 1});
        visited.insert({i, j + 1});
      }
    }
    return minimum_k_pair;
  }

 private:
  struct SumIndex {
    int sum;
    int num1_index;
    int num2_index;

    bool operator> (const SumIndex& other) const {
      return sum > other.sum;
    }
  };
};
