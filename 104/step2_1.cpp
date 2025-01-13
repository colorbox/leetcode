/*
Time : O(V + E)
Space : O(V)
*/
class Solution {
public:
  int maxDepth(TreeNode* root) {
    stack<pair<TreeNode*, int>> nodes_and_depths;
    nodes_and_depths.emplace(root, 0);
    int max_depth = 0;
    while (!nodes_and_depths.empty()) {
      auto [node, depth] = nodes_and_depths.top();
      nodes_and_depths.pop();
      if (node == nullptr) {
        continue;
      }
      max_depth = max(max_depth, depth + 1);
      nodes_and_depths.emplace(node->left, depth + 1);
      nodes_and_depths.emplace(node->right, depth + 1);
    }
    return max_depth;
  }
};
