// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == NULL)
//         {
//             return NULL;
//         }
//         if (root->val == val)
//         {
//             return root;
//         }

//         if (root->val > val) // left part
//         {
//             return searchBST(root->left, val);
//         }
//         else
//         {
//             return searchBST(root->right, val);
//         }
//     }
// };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->val == val) {
                return curr;
            }
            else if (curr->val > val) {
                curr = curr->left;   // move to left subtree
            }
            else {
                curr = curr->right;  // move to right subtree
            }
        }

        return NULL;  // value not found
    }
};

