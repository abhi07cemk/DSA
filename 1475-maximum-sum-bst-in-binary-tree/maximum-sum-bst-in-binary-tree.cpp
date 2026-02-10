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
    struct Info{
        int mini;
        int maxi;
        bool isBST;
        int sum;
    };

    Info solve(TreeNode* root, int &ans)
    {
        if(!root)
            return {INT_MAX,INT_MIN, true, 0};

        Info left = solve(root->left, ans);
        Info right = solve(root->right, ans);

        Info curr;
        curr.sum = left.sum + right.sum + root->val;
        curr.mini = min(root->val, left.mini);
        curr.maxi = max(root->val, right.maxi);

        if (left.isBST && right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            curr.isBST = true;
            ans = max(ans, curr.sum);
        } else {
            curr.isBST = false;
        }

        return curr;
    }



    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};