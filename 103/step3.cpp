class Solution {
  public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if (!root) {
       return {};
     }
     bool reverse_level = false;
     vector<vector<int>> level_ordered_vals;
     vector<TreeNode*> current_level_nodes = {root};
     while (!current_level_nodes.empty()) {
       vector<TreeNode*> next_level_nodes;
       level_ordered_vals.push_back({});
       for (int i = 0; i < current_level_nodes.size(); ++i) {
         auto node = current_level_nodes[i];
         if (node->left) {
           next_level_nodes.push_back(node->left);
         }
         if (node->right) {
           next_level_nodes.push_back(node->right);
         }
         level_ordered_vals.back().push_back(node->val);
       }
       if (reverse_level) {
         reverse(level_ordered_vals.back().begin(), level_ordered_vals.back().end());
       }
       reverse_level = !reverse_level;
       swap(next_level_nodes, current_level_nodes);
     }
     return level_ordered_vals;
   }
 };
 