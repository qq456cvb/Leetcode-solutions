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
    TreeNode *helper(vector<int>& preorder, int c, int d, vector<int>& inorder, int a, int b) {
        if (b < a || d < c) {
            return NULL;
        }
        TreeNode *parent = new TreeNode(preorder[c]);
        int it = a;
        while (inorder[it] != parent->val) {
            it++;
        }
        parent->left = helper(preorder, c+1, it-a+c, inorder, a, it-1);
        parent->right = helper(preorder, it-a+c+1, d, inorder, it+1, b);
        return parent;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};