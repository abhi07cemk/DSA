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
private:
    int height(TreeNode* node){
        //base case
        if(node == NULL) {
            return 0;
        }
        
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        return ans;
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        bool diff = abs(height(root -> left) - height(root -> right)) <= 1;

        if(left && right && diff)
        {
            return 1;
        }
        else
        {
            return false;
        }
    }
};

// class Solution {
// private:
//     int height(TreeNode* root) {
//         if (root == NULL) return 0;

//         int left = height(root->left);
//         if (left == -1) return -1;

//         int right = height(root->right);
//         if (right == -1) return -1;

//         if (abs(left - right) > 1) return -1;

//         return max(left, right) + 1;
//     }

// public:
//     bool isBalanced(TreeNode* root) {
//         return height(root) != -1;
//     }
// };
