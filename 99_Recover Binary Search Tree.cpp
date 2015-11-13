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
    vector<TreeNode*> candidates;
    TreeNode *lastNode = NULL;
public:
    void swap(TreeNode *a1, TreeNode *a2) {
        a1->val = a1->val ^ a2->val;
        a2->val = a1->val ^ a2->val;
        a1->val = a1->val ^ a2->val;
    }
    
    void midOrder(TreeNode *node) {
        if (node->left) {
            midOrder(node->left);
        }
        if (lastNode && node->val < lastNode->val) {
            this->candidates.push_back(lastNode);
            this->candidates.push_back(node);
            if (candidates.size() > 2) {
                return;
            }
        }
        lastNode = node;
        if (node->right) {
            midOrder(node->right);
        }
    }
    
    void recoverTree(TreeNode* root) {
        midOrder(root);
        if (this->candidates.size() == 2) {
            swap(this->candidates[0], this->candidates[1]);
        } else if (candidates.size() == 4) {
            swap(this->candidates[0], this->candidates[3]);
        }
    }
};