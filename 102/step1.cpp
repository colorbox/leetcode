/*
Solve Time: 21:38

Time : O(N^2)
Space : O(N^2)
*/
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    auto left = levelOrder(root->left);
    auto right = levelOrder(root->right);
    auto merged_level_vals = merge_two_trees(left, right);
    vector<vector<int>> level_order = {{root->val}};
    level_order.insert(level_order.end(), merged_level_vals.begin(), merged_level_vals.end());
    return level_order;
  }

 private:
  vector<vector<int>> merge_two_trees(vector<vector<int>>& left, vector<vector<int>>& right) {
    vector<vector<int>> merged_levels;
    for (int i = 0; i < max(left.size(), right.size()); ++i) {
      vector<int> current_level_vals;
      if (i < left.size()) {
        current_level_vals.insert(current_level_vals.end(), left[i].begin(), left[i].end());
      }
      if (i < right.size()) {
        current_level_vals.insert(current_level_vals.end(), right[i].begin(), right[i].end());
      }
      merged_levels.push_back(current_level_vals);
    }
    return merged_levels;
  }
};
