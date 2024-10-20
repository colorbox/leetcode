/*
struct不使用パターン
*/
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sum_index;
    set<vector<int>> visited;
    vector<vector<int>> answer;
    sum_index.push({0, 0, 0});
    while (answer.size() < k && sum_index.size() > 0) {
      int i = sum_index.top()[1];
      int j = sum_index.top()[2];
      sum_index.pop();
      answer.push_back({nums1[i], nums2[j]});
      if (i + 1 < nums1.size() && !visited.contains({i + 1, j})) {
        sum_index.push({nums1[i + 1] + nums2[j], i + 1, j});
        visited.insert({i + 1, j});
      }
      if (j + 1 < nums2.size() && !visited.contains({i, j + 1})) {
        sum_index.push({nums1[i] + nums2[j + 1], i, j + 1});
        visited.insert({i, j + 1});
      }
    }
    return answer;
  }
};
