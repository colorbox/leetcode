/*
Time: O(N)
Space: O(N)

nil判定を最初に置くことでwhileの条件やbreakを素直にした
*/
class Solution {
  public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if (!root) {
       return {};
     }
     bool reversed_level = false;
     vector<vector<int>> zigzag_level_ordered_vals;
     vector<TreeNode*> current_level_nodes = {root};
     while (!current_level_nodes.empty()) {
       vector<TreeNode*> next_level_nodes;
       vector<int> same_level_vals;
       for (int i = 0; i < current_level_nodes.size(); ++i) {
         if (!current_level_nodes[i]) {
           continue;
         }
         same_level_vals.push_back(current_level_nodes[i]->val);
         if (current_level_nodes[i]->left) {
           next_level_nodes.push_back(current_level_nodes[i]->left);
         }
         if (current_level_nodes[i]->right) {
           next_level_nodes.push_back(current_level_nodes[i]->right);
         }
       }
       if (reversed_level) {
         reverse(same_level_vals.begin(), same_level_vals.end());
       }
       reversed_level = !reversed_level;
       swap(current_level_nodes, next_level_nodes);
       zigzag_level_ordered_vals.push_back(same_level_vals);
     }
     return zigzag_level_ordered_vals;
   }
 };
