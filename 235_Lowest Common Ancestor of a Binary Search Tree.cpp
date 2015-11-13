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
    TreeNode *result;
public:
    int helper(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        int cnt = 0;
        if (node == p || node == q) {
            cnt++;
        }
        if (node->left) {
            cnt += helper(node->left, p, q);
        }
        if (node->right) {
            cnt += helper(node->right, p, q);
        }
        if (cnt == 2) {
            result = node;
            cnt = 0;
        }
        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return result;
    }
};