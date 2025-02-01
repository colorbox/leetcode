class Solution {
public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
      return nullptr;
    }
    stack<pair<vector<TreeNode*>, bool>> next_nodes;
    auto merged_root = new TreeNode();
    if (!root1) {
      root1 = new TreeNode();
    }
    if (!root2) {
      root2 = new TreeNode();
    }
    merged_root->val += root1->val + root2->val;
    next_nodes.push({{root1->left, root2->left, merged_root}, true});
    next_nodes.push({{root1->right, root2->right, merged_root}, false});
    while (!next_nodes.empty()) {
      auto [nodes, is_left] = next_nodes.top();
      next_nodes.pop();
      auto node1 = nodes[0];
      auto node2 = nodes[1];
      auto parent_node = nodes[2];
      if (!node1 && !node2) {
        continue;
      }
      int merged_val = (node1 ? node1->val : 0) + (node2 ? node2->val : 0);
      auto merged_node = new TreeNode(merged_val);
      if (is_left) {
        parent_node->left = merged_node;
      } else {
        parent_node->right = merged_node;
      }
      next_nodes.push({{(node1 ? node1->left : nullptr), (node2 ? node2->left : nullptr), merged_node}, true});
      next_nodes.push({{(node1 ? node1->right : nullptr), (node2 ? node2->right : nullptr), merged_node}, false});
    }
    return merged_root;
  }
};
