/*
Time : O(V + E)
Space : O(V)

再帰,DFSで解いてみる。
rootの処理をどうしても分岐で処理できなかったので最初のrootの面倒を見る関数と再帰処理をする関数とに分けた。
*/
class Solution {
public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return minDepthRecursive(root);
  }
 private:
  int minDepthRecursive(TreeNode* root) {
    if (!root) {
      return numeric_limits<int>::max();
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    return min(minDepthRecursive(root->left), minDepthRecursive(root->right)) + 1;
  }
};
