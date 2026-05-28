/*
Time : O(N)
Space : O(N)
インデックスを使用してvectorのコピーをなくした。
*/
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sorted_array_to_bst_recursive(nums, 0, nums.size());
  }

 private:
  TreeNode* sorted_array_to_bst_recursive(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return nullptr;
    }
    int mid = (left + right) / 2;
    auto node = new TreeNode(nums[mid]);
    node->left = sorted_array_to_bst_recursive(nums, left, mid);
    node->right = sorted_array_to_bst_recursive(nums, mid + 1, right);
    return node;
  }
};
