// 引数名を変えて　高さであることを直感的にわかるようにした
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int left_height = height(root->left, 0);
        int right_height = height(root->right, 0);

        return abs(right_height - left_height) <=1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root, int base_height) {
        if (!root) {
            return base_height;
        }

        int left_height = height(root->left, base_height);
        int right_height = height(root->right, base_height);

        return max(left_height, right_height) + 1;
    }
};
