/*
2_1_1を理解するために番兵を除去したコード
left_limitは左部分木の右側の限界位置、right_limitが右部分木の右側の限界位置をそれぞれ示す
それがstackに積んだrootを含むtupleから直感的に理解できる
forの中にwhileと捉えるとわかりづらくなるが、シンプルにpreorder traversalと捉えるとわかりやすくなる
*/
class Solution {
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      map<int, int> value_to_inorder_position;
      for (int i = 0; i < inorder.size(); i++) {
          value_to_inorder_position[inorder[i]] = i;
      }
      auto root = new TreeNode(preorder[0]);
      stack<tuple<TreeNode*, int, int>> nodes_and_limits;
      nodes_and_limits.push({root, value_to_inorder_position[root->val], preorder.size()});
      for (int i = 1; i < preorder.size(); ++i) {
        auto p = preorder[i];
        auto node = new TreeNode(p);
        auto node_inorder_index = value_to_inorder_position[node->val];
        auto [parent_node, parent_left_limit, parent_right_limit] = nodes_and_limits.top();
        if (node_inorder_index < parent_left_limit) {
          parent_node->left = node;
          nodes_and_limits.push({node, node_inorder_index, parent_left_limit});
          continue;
        }
        while (!nodes_and_limits.empty()) {
          auto [parent_node, parent_left_limit, parent_right_limit] = nodes_and_limits.top();
          if (node_inorder_index < parent_right_limit) {
            nodes_and_limits.pop();
            parent_node->right = node;
            // 左部分木のrootをstackにpushする時に、right_limitが親のleft_limitになるのは、親の位置が右部分木の限界位置だから
            // 右部分木のrootをstackにpushする時、親のright_limitがそのまま使われるのは、親の位置によって右部分木の限界位置が定まらないから
            nodes_and_limits.push({node, node_inorder_index, parent_right_limit});
            break;
          }
          nodes_and_limits.pop();
        }
      }
  
      return root;
    }
  };
  