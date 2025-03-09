/*
Solve Time : 07:17

Time : O(V + E)
Space : O(V)

root ~ leafまでの距離、という部分を読み違えて時間を多少ロスしたものの、特につまるところなく解けた。
*/
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
      if (node->left == nullptr && node->right == nullptr) {
        return depth;
      }
      nodes_and_depths.emplace(node->left, depth + 1);
      nodes_and_depths.emplace(node->right, depth + 1);      
    }
    return 0;
  }
};
