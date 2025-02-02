/*
Time : O(N)
Space : O(N)

再帰を使わずに実装。
https://github.com/colorbox/leetcode/pull/37
を説いたときにある程度理解したつもりだったが、ポインタのポインタを使おうとするとだいぶ混乱する。

*/
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    stack<tuple<TreeNode**, int, int>> parents_and_ranges;
    TreeNode *node;
    parents_and_ranges.emplace(&node, 0, nums.size());
    while (!parents_and_ranges.empty()){
      auto [parent_node_pointer, left, right] = parents_and_ranges.top();
      parents_and_ranges.pop();
      if (left >= right) {
        continue;
      }
      int mid = (left + right) / 2;
      TreeNode* parent_node = new TreeNode(nums[mid]);
      *parent_node_pointer = parent_node;
      parents_and_ranges.emplace(&parent_node->left, left, mid);
      parents_and_ranges.emplace(&parent_node->right, mid + 1, right);
    }
    return node;
  }
};
