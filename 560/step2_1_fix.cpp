/*
exclusive_scanを使用して累積和配列を作成したパターン。
また、変数による名前付けでコードを読みやすくしている。
*/
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    vector<int> cumulative_nums(nums.size());
    exclusive_scan(nums.begin(), nums.end(), cumulative_nums.begin(), 0);
    cumulative_nums.push_back(cumulative_nums.back() + nums.back());

    int subarray_count = 0;
    map<int, int> cumulative_num_to_count;
    for (int i = cumulative_nums.size() - 1; i > 0; --i) {
      cumulative_num_to_count[cumulative_nums[i]]++;
      int from_cumulative_num = cumulative_nums[i - 1];
      subarray_count += cumulative_num_to_count[from_cumulative_num + k];
    }
    return subarray_count;
  }
};
