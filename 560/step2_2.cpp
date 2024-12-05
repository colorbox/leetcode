/*
Time : O(N)
Space : O(N)

他の人のコードを参考にstep2_1を改良したもの。
累積和の捉え方に関しては駅と標高の例えがかなりしっくりきた。
*/
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int subarray_count = 0;
    int cumulative_num = 0;
    map<int, int> cumulative_num_to_count;
    cumulative_num_to_count[0] = 1;
    for (int num : nums) {
      cumulative_num += num;
      subarray_count += cumulative_num_to_count[cumulative_num - k];
      ++cumulative_num_to_count[cumulative_num];
    }
    return subarray_count;
  }
};
