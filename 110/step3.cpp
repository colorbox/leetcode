// デフォルト引数を使用
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);

        return abs(right_height - left_height) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root, int base_height = 0) {
        if (!root) {
            return base_height;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);

        return max(left_height, right_height) + 1;
    }
};
