class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> level_order = {{root->val}};
    auto left_level_order = levelOrder(root->left);
    auto right_level_order = levelOrder(root->right);
    for (int i = 0; i < max(left_level_order.size(), right_level_order.size()); ++i) {
      vector<int> same_level_values;
      if (i < left_level_order.size()) {
        same_level_values.insert(same_level_values.end(), left_level_order[i].begin(), left_level_order[i].end());
      }
      if (i < right_level_order.size()) {
        same_level_values.insert(same_level_values.end(), right_level_order[i].begin(), right_level_order[i].end());
      }
      level_order.push_back(same_level_values);
    }
    return level_order;
  }
};
