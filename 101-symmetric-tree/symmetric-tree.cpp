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
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both are NULL, symmetric
        if (left == nullptr && right == nullptr)
            return true;
        
        // If one is NULL, not symmetric
        if (left == nullptr || right == nullptr)
            return false;
        
        // Check values and recursive mirror condition
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return isMirror(root->left, root->right);
    }
};
