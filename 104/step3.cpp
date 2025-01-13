class Solution {
public:
  int maxDepth(TreeNode* root) {
    queue<pair<TreeNode*, int>> nodes_and_depths;
    nodes_and_depths.emplace(root, 0);
    int max_depth = 0;
    while (!nodes_and_depths.empty()) {
      auto [node, depth] = nodes_and_depths.front();
      nodes_and_depths.pop();
      max_depth = depth;
      if (!node) {
        continue;
      }
      nodes_and_depths.emplace(node->left, depth + 1);
      nodes_and_depths.emplace(node->right, depth + 1);
    }
    return max_depth;
  }
};
