/*
https://github.com/kazukiii/leetcode/pull/30#discussion_r1821628634
を理解するための練習
inorder traversalの動きに合わせて構築も同時にしていると捉えるとわかりやすかった
大筋としては、inorder順の処理、preorderの位置情報、の二点を活用することで構築を行っている。
inorderの順番で処理しているので、特定のノードの処理が完了すると、そのノードをrootとする部分木の構築が完了している。

*/
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> value_to_preorder_position;
    for (int i = 0; i < preorder.size(); ++i) {
      value_to_preorder_position[preorder[i]] = i;
    }
    stack<TreeNode*> nodes;
    // 
    auto gather_descendants = [&](int node_position) {
      TreeNode* child = nullptr;
      while (!nodes.empty()) {
        auto back = nodes.top();
        // stackの
        if (value_to_preorder_position[back->val] < node_position) {
          break;
        }
        nodes.pop();
        back->right = child;
        child = back;
      }
      return child;
    };
    for (int i: inorder) {
      auto node = new TreeNode(i);
      int node_position = value_to_preorder_position[node->val];
      // inorder順に処理している
      node->left = gather_descendants(node_position);
      nodes.push(node);
    }
    return gather_descendants(-1);
  }
};
