class Solution {
private:
    int diameter = 0;

    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        // Update diameter (edges)
        diameter = max(diameter, left + right);

        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
