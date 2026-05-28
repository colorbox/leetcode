/*
再帰は慣れているので、ポインタに慣れるためにポインタを使用した解法でstep3
*/
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    stack<tuple<TreeNode**, int, int>> node_pointers_and_ranges;
    TreeNode* root;
    node_pointers_and_ranges.emplace(&root, 0, nums.size());
    while (!node_pointers_and_ranges.empty()) {
      auto [node_pointer, left, right] = node_pointers_and_ranges.top();
      node_pointers_and_ranges.pop();
      if (left >= right) {
        continue;
      }
      int mid = (left + right) / 2;
      TreeNode* node = new TreeNode(nums[mid]);
      *node_pointer = node;
      node_pointers_and_ranges.emplace(&node->left, left, mid);
      node_pointers_and_ranges.emplace(&node->right, mid + 1, right);
    }
    return root;
  }
};
