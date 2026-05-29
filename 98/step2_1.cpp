/*
Time: O(N)
Space: O(N)

下限と上限を持って再帰を構築する。
step1でこういった解法に思い至れなかったのは、関数を分けるという発想が出来ず
同時に複数のことを一つの関数でやろうとして混乱していた
思考中に負荷を感じたら何らかを分割するみたいな考え方が必要そう
*/
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (!root) {
      return true;
    }
    return is_valid_bst_recursive(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
  }

 private:
  bool is_valid_bst_recursive(TreeNode* node, int64_t left_val, int64_t right_val) {
    if (!node) {
      return true;
    }
    if (!(left_val < node->val && node->val < right_val)) {
      return false;
    }
    return is_valid_bst_recursive(node->left, left_val, node->val) && is_valid_bst_recursive(node->right, node->val, right_val);
  }
};
