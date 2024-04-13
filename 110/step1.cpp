// 高さ平衡の定義を勘違いしておりパスできなかったので解説を見て書く
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left_height = recursive_max_height(root->left, 0);
        int right_height = recursive_max_height(root->right, 0);

        return abs(right_height - left_height) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int recursive_max_height(TreeNode* root, int current_height) {
        if (root == nullptr) {
            return current_height - 1;
        }

        int left_height = recursive_max_height(root->left, current_height + 1);
        int right_height = recursive_max_height(root->right, current_height + 1);

        return max(left_height, right_height);
    }
};
