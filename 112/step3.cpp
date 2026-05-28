class Solution {
public:
  bool hasPathSum(TreeNode* root, int target_sum) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      return target_sum == root->val;
    }
    return hasPathSum(root->left, target_sum - root->val) || hasPathSum(root->right, target_sum - root->val);
  }
};
