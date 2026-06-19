class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) {
      return nullptr;
    }
    auto root = new TreeNode(preorder[0]);
    int inorder_root_index;
    for (int i = 0; i <  inorder.size(); ++i) {
      if (inorder[i] == root->val) {
        inorder_root_index = i;
        break;
      }
    }

    vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + inorder_root_index);
    vector<int> left_inorder(inorder.begin(), inorder.begin() + inorder_root_index);
    root->left = buildTree(left_preorder, left_inorder);

    vector<int> right_preorder(preorder.begin() + 1 + inorder_root_index, preorder.end());
    vector<int> right_inorder(inorder.begin() + 1 + inorder_root_index, inorder.end());
    root->right = buildTree(right_preorder, right_inorder);

    return root;
  }
};
