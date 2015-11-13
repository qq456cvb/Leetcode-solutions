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
    TreeNode *helper(vector<int>& inorder, int a, int b, vector<int>& postorder, int c, int d) {
        if (b < a || d < c) {
            return NULL;
        }
        TreeNode *parent = new TreeNode(postorder[d]);
        int it = a;
        while (inorder[it] != parent->val) {
            it++;
        }
        parent->left = helper(inorder, a, it-1, postorder, c, it-a+c-1);
        parent->right = helper(inorder, it+1, b, postorder, it-a+c, d-1);
        return parent;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};