/*
Solve Time : 2:56

Time : O(V + E)
Space : O(V)

特に問題なく解いた、ひとまず一番シンプルにかける再帰を使用したが、queueやstackを使用したほうがよいはず。
*/
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    const int left_depth = maxDepth(root->left);
    const int right_depth = maxDepth(root->right);
    return max(left_depth, right_depth) + 1;
  }
};
