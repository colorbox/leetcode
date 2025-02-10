/*
Time : O(N)
Space : O(N)

再帰ではなく、stackを使って実装
*/
class Solution {
public:
  bool hasPathSum(TreeNode* root, int target_sum) {
    stack<pair<TreeNode*, int>> nodes_and_sums;
    nodes_and_sums.emplace(root, target_sum);
    while (!nodes_and_sums.empty()) {
      auto [node, sum] = nodes_and_sums.top();
      nodes_and_sums.pop();
      if (!node) {
        continue;
      }
      if (!node->left && !node->right && sum == node->val) {
        return true;
      }
      nodes_and_sums.emplace(node->left, sum - node->val);
      nodes_and_sums.emplace(node->right, sum - node->val);
    }
    return false;
  }
};
