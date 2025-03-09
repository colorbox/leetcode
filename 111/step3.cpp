class Solution {
public:
  int minDepth(TreeNode* root) {
    queue<pair<TreeNode*, int>> nodes_and_depths;
    nodes_and_depths.emplace(root, 1);
    while (!nodes_and_depths.empty()) {
      auto [node, depth] = nodes_and_depths.front();
      nodes_and_depths.pop();
      if (!node) {
        continue;
      }
      if (!(node->left || node->right)) {
        return depth;
      }
      nodes_and_depths.emplace(node->left, depth + 1);
      nodes_and_depths.emplace(node->right, depth + 1);
    }
    return 0;
  }
};
