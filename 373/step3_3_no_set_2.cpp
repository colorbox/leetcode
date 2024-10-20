/*
https://github.com/colorbox/leetcode/pull/25#discussion_r1766166184
https://github.com/seal-azarashi/leetcode/pull/10/files#diff-1738c7b2b125c2158f2d6502754f18d9c179c559fca2b92d22d1a6bfc16ce429
上記を参考にしたコード
一旦1行目の候補をすべてpriority_queueにpushし、その後取り出した候補を一つずつ降下させることで重複なく候補を取り出す。
*/
class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<SumIndex> k_pair_candidates;
    vector<vector<int>> minimum_k_pair;
    for (int i = 0; i < nums1.size(); i++) {
      k_pair_candidates.push({nums1[i] + nums2[0], i, 0});
    }
    while (minimum_k_pair.size() < k && k_pair_candidates.size() > 0) {
      auto [sum, i, j] = k_pair_candidates.top();
      k_pair_candidates.pop();
      minimum_k_pair.push_back({nums1[i], nums2[j]});
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
