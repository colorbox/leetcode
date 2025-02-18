/*
Time : O(N)
Space : O(N)

再帰を用いずに書いてみる。
currentはnextとの対比として自然なので使用した。
XXX_level_nodesはちょっと変数名がくどすぎる気もしたが、今見ているlevelというのを強調できるのでcurrent_nodesなどよりも適切に感じる。

*/
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> level_order;
    queue<TreeNode*> current_level_nodes;
    queue<TreeNode*> next_level_nodes;
    current_level_nodes.push(root);
    while (true) {
      vector<int> same_level_vals;
      while (!current_level_nodes.empty()) {
        auto node = current_level_nodes.front();
        current_level_nodes.pop();
        if (!node) {
          continue;
        }
        same_level_vals.push_back(node->val);
        next_level_nodes.push(node->left);
        next_level_nodes.push(node->right);
      }
      swap(current_level_nodes, next_level_nodes);
      if (same_level_vals.empty()) {
        break;
      }
      level_order.push_back(same_level_vals);
    }
    return level_order;
  }
};
