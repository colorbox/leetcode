/*
Solve Time : 09:16

Time : O(V)
Space : O(V)

rootの宣言周りのミスで無駄に手間取ってしまった。
newをつかうべきだったがそれを失念していた。
それ以外は特に問題なくクリア、気分的にとりあえず再帰で解いた。
*/
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
      return nullptr;
    }
    if (!root1) {
      return root2;
    } 
    if (!root2) {
      return root1;
    }
    TreeNode *root = new TreeNode(root1->val + root2->val);
    root->left = mergeTrees(root1->left, root2->left);
    root->right = mergeTrees(root1->right, root2->right);
    return root;
  }
};
