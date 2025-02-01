/*
Time : O(V)
Space : O(V)

ポインタを用いて簡略化したもの
*/
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
      return nullptr;
    }
    stack<tuple<TreeNode*, TreeNode*, TreeNode**>> next_nodes;
    auto merged_root = new TreeNode();
    next_nodes.push({root1, root2, &merged_root});
    while (!next_nodes.empty()) {
      auto [node1, node2, merged_node_ptr] = next_nodes.top();
      next_nodes.pop();
      if (!node1 && !node2) {
        continue;
      }
      int merged_val = (node1 ? node1->val : 0) + (node2 ? node2->val : 0);
      TreeNode* merged_node = new TreeNode(merged_val);
      *merged_node_ptr = merged_node;
      next_nodes.push({(node1 ? node1->left : nullptr), (node2 ? node2->left : nullptr), &merged_node->left});
      next_nodes.push({(node1 ? node1->right : nullptr), (node2 ? node2->right : nullptr), &merged_node->right});
    }
    return merged_root;
  }
};
