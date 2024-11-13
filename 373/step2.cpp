/*
他の方の回答を参考にやり直したもの
nums1,nums2のインデックスのペアをダイクストラ法っぽく処理していく
Time: O(k logk)
Space: O(k)
*/
class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<SumIndex, vector<SumIndex>, greater<SumIndex>> sum_index;
    set<vector<int>> visited;
    vector<vector<int>> answer;
    sum_index.push({nums1[0] + nums2[0], {0, 0}});
    while (answer.size() < k) {
      int i = sum_index.top().index[0];
      int j = sum_index.top().index[1];
      sum_index.pop();
      answer.push_back({nums1[i], nums2[j]});
      if (i + 1 < nums1.size() && !visited.contains({i + 1, j})) {
        sum_index.push({nums1[i + 1] + nums2[j], {i + 1, j}});
        visited.insert({i + 1, j});
      }
      if (j + 1 < nums2.size() && !visited.contains({i, j + 1})) {
        sum_index.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        visited.insert({i, j + 1});
      }
    }

    return answer;
  }

 private:
  struct SumIndex {
    int sum;
    vector<int> index;

    bool operator> (const SumIndex& other) const {
      return sum > other.sum;
    }
  };
};
