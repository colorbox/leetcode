/*
Time: O(N)
Space: O(N)

in-order走査でvalがソートされるBSTの性質を利用した解法

*/
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (!root) {
      return true;
    }
    vector<int> sorted_vals;
    stack<TreeNode*> in_order_operating_nodes;
    in_order_operating_nodes.push(root);
    while (in_order_operating_nodes.top()->left) {
      in_order_operating_nodes.push(in_order_operating_nodes.top()->left);
    }
    while (!in_order_operating_nodes.empty()) {
      auto node = in_order_operating_nodes.top();
      in_order_operating_nodes.pop();
      sorted_vals.push_back(node->val);
      if (node->right) {
        in_order_operating_nodes.push(node->right);
        while (in_order_operating_nodes.top()->left) {
          in_order_operating_nodes.push(in_order_operating_nodes.top()->left);
        }
      }
    }
    for (int i = 0; i < sorted_vals.size() - 1; ++i) {
      if (sorted_vals[i] >= sorted_vals[i+1]) {
        return false;
      }
    }
    return true;
  }
};
