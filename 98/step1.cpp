/*
Solve Time: 18:52

Time: O(N^2)
Space: O(N)

最初、部分木の最大値/最小値の算出とBST判定を同時にやろうとしてハマりかけたのでそれぞれの判定を関数に切り出してシンプルにした
同時にいろんなことをしようとすると、書くのも読むのも大変なコードになりそう、というかそういうコードを考えること自体が負荷だった

*/
class Solution {
  public:
    bool isValidBST(TreeNode* root) {
      if (!root) {
        return true;
      }
      if (!isValidBST(root->left) || !isValidBST(root->right)) {
        return false;
      }
      if (root->left && max_val_in_tree(root->left) >= root->val) {
        return false;
      }
      if (root->right && min_val_in_tree(root->right) <= root->val) {
        return false;
      }
      return true;
    }
  private:
    int max_val_in_tree(TreeNode* root) {
      int max_val = root->val;
      if (root->left) {
        max_val = max(max_val, max_val_in_tree(root->left));
      }
      if (root->right) {
        max_val = max(max_val, max_val_in_tree(root->right));
      }
      return max_val;
    }
  
    int min_val_in_tree(TreeNode* root) {
      int min_val = root->val;
      if (root->left) {
        min_val = min(min_val, min_val_in_tree(root->left));
      }
      if (root->right) {
        min_val = min(min_val, min_val_in_tree(root->right));
      }
      return min_val;
  
    }
  };
  