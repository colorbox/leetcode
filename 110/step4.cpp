// 繰り返し呼ばれるheightについて、キャッシュで高速化を試みたがむしろ低速化した
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

    map<TreeNode*, int> height_cache;
    int height(TreeNode* root, int base_height = 0) {
        if (height_cache.count(root)) {
            return height_cache[root];
        }
        if (!root) {
            return base_height;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);

        height_cache[root] = max(left_height, right_height)+1;
        return height_cache[root];
    }
};
