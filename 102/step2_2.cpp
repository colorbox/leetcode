class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> level_ordered_nums;
    vector<TreeNode*> current_level_nodes = {root};
    while (!current_level_nodes.empty()) {
      vector<TreeNode*> next_level_nodes;
      vector<int> same_level_nums;
      for (int i = 0; i < current_level_nodes.size(); ++i) {
        if (!current_level_nodes[i]) {
          continue;
        }
        same_level_nums.push_back(current_level_nodes[i]->val);
        next_level_nodes.push_back(current_level_nodes[i]->left);
        next_level_nodes.push_back(current_level_nodes[i]->right);
      }
      if (same_level_nums.empty()) {
        break;
      }
      level_ordered_nums.push_back(same_level_nums);
      swap(current_level_nodes, next_level_nodes);
    }
    return level_ordered_nums;
 }
};
