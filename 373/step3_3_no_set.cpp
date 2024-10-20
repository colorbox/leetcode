/*
https://github.com/colorbox/leetcode/pull/25#discussion_r1759948961
https://github.com/ryoooooory/LeetCode/pull/17/files#diff-1288c579d3218c63304f49c9c9a04568c3305bef4a38145045001270d6f6b5c6
を参考としたコード
右・下移動をpriority_queueから取り出すごとに行うが、下移動は一番上にいるときのみに限って行うことで、衝突を避ける。
*/
class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<SumIndex> k_pair_candidates;
    vector<vector<int>> minimum_k_pair;
    k_pair_candidates.push({nums1[0] + nums2[0], 0, 0});
    while (minimum_k_pair.size() < k && k_pair_candidates.size() > 0) {
      auto [sum, i, j] = k_pair_candidates.top();
      k_pair_candidates.pop();
      minimum_k_pair.push_back({nums1[i], nums2[j]});
      if (j == 0 && i + 1 < nums1.size()) {
        k_pair_candidates.push({nums1[i + 1] + nums2[j], i + 1, j});
      }
      if (j + 1 < nums2.size()) {
        k_pair_candidates.push({nums1[i] + nums2[j + 1], i, j + 1});
      }
    }
    return minimum_k_pair;
  }

 private:
  struct SumIndex {
    int sum;
    int num1_index;
    int num2_index;

    bool operator< (const SumIndex& other) const {
      return sum > other.sum;
    }
  };
};
