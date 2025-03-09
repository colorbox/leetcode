class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return is_valid_bst_recursive(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
  }

 private:
  bool is_valid_bst_recursive(TreeNode* node, int64_t under_limit, int64_t upper_limit) {
    if (!node) {
      return true;
    }
    if (node->val <= under_limit || upper_limit <= node->val) {
      return false;
    }
    return is_valid_bst_recursive(node->left, under_limit, node->val) &&
      is_valid_bst_recursive(node->right, node->val, upper_limit);
  }
};
