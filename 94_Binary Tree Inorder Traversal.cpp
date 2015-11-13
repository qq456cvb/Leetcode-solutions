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
    vector<int> result;
public:
    void helper(TreeNode *node) {
        if (node) {
            helper(node->left);
            result.push_back(node->val);
            helper(node->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return result;
    }
};