/*
Solve Time : 21:05

Time: O(N^2)
Space: O(N)
*/
class Solution {
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if (preorder.size() == 0) {
        return nullptr;
      }
      // preorder_first element is root
      auto root = new TreeNode(preorder[0]);
      if (preorder.size() == 1) {
        return root;
      }
      // get index of root in inorder
      int inorder_root_index;
      for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == preorder[0]) {
          inorder_root_index = i;
          break;
        }
      }
      // get left right tree node count
      int left_nodes_count = inorder_root_index;
      // split vectors and recursive to left right
      vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + left_nodes_count);
      vector<int> inorder_left(inorder.begin(), inorder.begin() + left_nodes_count);
      root->left = buildTree(preorder_left, inorder_left);
  
      vector<int> preorder_right(preorder.begin() + left_nodes_count + 1, preorder.end());
      vector<int> inorder_right(inorder.begin() + left_nodes_count + 1, inorder.end());
      root->right = buildTree(preorder_right, inorder_right);
      return root;
    }
  };
