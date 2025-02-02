/*
Time : O(N log N)
Space : O(N)

nums.size==1の無駄な処理減らし、vectorのコピーをループを使わずに実行するようにした。
*/
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
      return nullptr;
    }
    int center_index = nums.size() / 2;
    auto node = new TreeNode(nums[center_index]);
    auto left_nodes = vector<int>(nums.begin(), nums.begin() + center_index);
    node->left = sortedArrayToBST(left_nodes);
    auto right_nodes = vector<int>(nums.begin() + center_index + 1, nums.end());
    node->right = sortedArrayToBST(right_nodes);
    return node;
  }
};
