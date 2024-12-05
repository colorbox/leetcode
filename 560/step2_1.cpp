/*
Time : O(N log N)
Space : O(N)

step1で解けなかったO(N log N)の解法。
色々思考を整理して書いたところ問題なく行けた。
このあたりの思考スピードが課題。
*/
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    vector<int> cumulative_nums = {0};
    for (int num : nums) {
      cumulative_nums.push_back(cumulative_nums.back() + num);
    }
    int subarray_count = 0;
    map<int, int> cumulative_num_to_count;
    for (int i = cumulative_nums.size() - 1; i > 0; --i) {
      cumulative_num_to_count[cumulative_nums[i]]++;
      subarray_count += cumulative_num_to_count[k + cumulative_nums[i - 1]];
    }
    return subarray_count;
  }
};
