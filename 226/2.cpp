/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return nullptr; }

        queue<TreeNode*> node_queue;
        node_queue.push(root);

        while (!node_queue.empty()) {
            TreeNode* current_node = node_queue.front();
            node_queue.pop();

            swap(current_node->left, current_node->right);
            if (current_node->left) { node_queue.push(current_node->left); }
            if (current_node->right) { node_queue.push(current_node->right); }
        }

        return root;
    }
};
