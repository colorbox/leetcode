/*
Time: O(N)
Space: O(N)
https://github.com/kazukiii/leetcode/pull/30#discussion_r1821506570
のコードが直感的に理解しづらかったので理解のために書いた
大筋の処理としては、preorderの順番に処理、inorderの位置情報を利用。
inorderの、特定のノードを境に左部分木と右部分木に分かれる性質を活用する。

*/
class Solution {
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      map<int, int> value_to_inorder_position;
      for (int i = 0; i < inorder.size(); i++) {
          value_to_inorder_position[inorder[i]] = i;
      }
      TreeNode dummy = TreeNode();
      stack<tuple<TreeNode*, int, int>> nodes_and_limits;
      // 番兵の設置、left/rightのlimitはinorderにおける左右部分木の存在可能な限界を示す、番兵の初期値としてmaxを与える
      nodes_and_limits.push({&dummy, numeric_limits<int>::max(), numeric_limits<int>::max()});
      for (int p: preorder) {
        auto node = new TreeNode(p);
        auto node_inorder_position = value_to_inorder_position[p];
        auto [parent_node, parent_left_limit, parent_right_limit] = nodes_and_limits.top();
        // inorderの位置が、暫定親親の持つ左部分木の限界よりも小さい場合、暫定親は親に確定、その左部分木にnodeを追加する
        // preorderを順番に処理しているので、inorderにおける下記位置条件を満たすなら、常に直前の要素の左部分木のrootとなる
        if (node_inorder_position < parent_left_limit) {
          parent_node->left = node;
          nodes_and_limits.push({node, node_inorder_position, parent_left_limit});
          continue;
        }
        // 左部分木に関する条件を満たさないので、右部分木の始点を探す
        while (!nodes_and_limits.empty()) {
          // 現在処理中のnodeのinorderにおける位置が、暫定親の右部分木の限界よりも小さい場合、その暫定親の右部分木のrootとして追加する
          auto [parent_node, parent_left_limit, parent_right_limit] = nodes_and_limits.top();
          // 暫定親(stack末尾ノード)の右部分木の上限よりも小さいなら、そこが右部分木の始点となる
          // ここに到達するまでに処理した暫定親は右部分木の限界がnodeの位置よりも左にあるため、右部分木の始点となれない
          if (node_inorder_position < parent_right_limit) {
            // 右部分木の親が確定したら右部分木を生やして新たな処理対応としてstackへpush
            parent_node->right = node;
            nodes_and_limits.pop();
            nodes_and_limits.push({node, node_inorder_position, parent_right_limit});
            break;
          }
          // 次の暫定親の確認のためpop
          nodes_and_limits.pop();
        }
      }
      return dummy.left;
    }
  };
  