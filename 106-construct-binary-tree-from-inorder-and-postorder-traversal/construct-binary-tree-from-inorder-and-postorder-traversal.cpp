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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int postIndex = postorder.size() - 1;
        return solve(inorder, postorder, postIndex, 0, inorder.size() - 1, mp);
    }

private:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& postIndex, int inStart, int inEnd,
                    unordered_map<int,int>& mp) {
        if(postIndex < 0 || inStart > inEnd)
            return NULL;

        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);

        int position = mp[element];

        root->right = solve(inorder, postorder, postIndex,
                            position + 1, inEnd, mp);

        root->left = solve(inorder, postorder, postIndex,
                           inStart, position - 1, mp);

        return root;
    }
};
