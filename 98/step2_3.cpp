/*
Time: O(N)
Space: O(N)

in-order走査のメモリ改良版

*/
class Solution {
  public:
    bool isValidBST(TreeNode* root) {
      if (!root) {
        return true;
      }
      stack<TreeNode*> in_order_operating_nodes;
      in_order_operating_nodes.push(root);
      TreeNode* checking_node;
      int64_t under_limit = numeric_limits<int64_t>::min();
      while (in_order_operating_nodes.top()->left) {
        in_order_operating_nodes.push(in_order_operating_nodes.top()->left);
      }
      while (!in_order_operating_nodes.empty()) {
        auto node = in_order_operating_nodes.top();
        in_order_operating_nodes.pop();
        if (under_limit >= node->val) {
          return false;
        }
        under_limit = node->val;
        if (node->right) {
          in_order_operating_nodes.push(node->right);
          while (in_order_operating_nodes.top()->left) {
            in_order_operating_nodes.push(in_order_operating_nodes.top()->left);
          }
        }
      }
      return true;
    }
  };
  