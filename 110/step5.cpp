// キャッシュを使わずにO(N)となるコード
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_height = getHeight(root->left);
        if (left_height == -1) {
            return -1;
        }

        int right_height = getHeight(root->right);
        if (right_height == -1) {
            return -1;
        }

        if (abs(left_height - right_height) > 1) {
            return -1;
        }

        return max(left_height, right_height) + 1;
    }

};
