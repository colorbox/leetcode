/*
Solve Time : 30:20

Time : O(N^2)
Space : O(N)

まず素朴にO(N^3)の解法を思いつき、次にそれを効率化するO(N^2)の解法を思いつく。
それをmapでもう一段階高速化できそうと思い実装したがこんがらがって時間がかかりすぎてしまったのでひとまずO(N^2)の解法で解く。
*/
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    vector<int> cumulative_nums = {0};
    for (int num : nums) {
      cumulative_nums.push_back(cumulative_nums.back() + num);
    }
    int subarray_count = 0;
    for (int i = 0; i < cumulative_nums.size(); ++i) {
      for (int j = i + 1; j < cumulative_nums.size(); ++j) {
        if (cumulative_nums[j] - cumulative_nums[i] == k) {
          subarray_count++;
        }
      }
    }
    return subarray_count;
  }
};
