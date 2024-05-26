/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* current = root;
        TreeNode* left = p;
        TreeNode* right = q;

        if (left->val > right->val) {
            swap(left, right);
        }

        while (true) {
            if (current->val < left->val) {
                current = current->right;
                continue;
            }

            if (current->val > right->val) {
                current = current->left;
                continue;
            }

          return current;
        }
    }
};
