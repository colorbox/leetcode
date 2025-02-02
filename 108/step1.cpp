/*
Solve Time : 23:54

Time : O(N log N)
Space : (N)

方針はほぼ最初にできていたが、右側の再帰部分でミスってハマった。
右半分をreverseして再帰しないといけないという勘違いをしていた。
*/
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) {
      return nullptr;
    }
    if (nums.size() == 1) {
      return new TreeNode(nums[0]);
    }
    int half_size = nums.size() / 2;
    vector<int> left_nums;
    for (int i = 0; i < half_size; ++i) {
      left_nums.push_back(nums[i]);
    }
    vector<int> right_nums;
    for (int i = half_size + 1; i < nums.size(); ++i) {
      right_nums.push_back(nums[i]);
    }
    return new TreeNode(nums[half_size], sortedArrayToBST(left_nums), sortedArrayToBST(right_nums));
  }
};
