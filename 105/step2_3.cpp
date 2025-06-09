/*
step1をインデックスを使用して高速化するパターン
*/
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {


    return buildTreeWithIndex(0, 0, preorder.size(), preorder, inorder);
  }

  TreeNode* buildTreeWithIndex(int preorder_root_index, int inorder_left, int inorder_right, vector<int>& preorder, vector<int>& inorder) {
    if (inorder_left >= inorder_right) {
      return nullptr;
    }
    auto root = new TreeNode(preorder[preorder_root_index]);

    int root_index;
    for (int i = inorder_left; i < inorder_right; ++i) {
      if (inorder[i] == root->val) {
        root_index = i;
        break;
      }
    }
    root->left = buildTreeWithIndex(preorder_root_index + 1, inorder_left, root_index, preorder, inorder);
    root->right = buildTreeWithIndex(preorder_root_index + 1 + (root_index - inorder_left), root_index + 1, inorder_right, preorder, inorder);
    return root;
  }
};
