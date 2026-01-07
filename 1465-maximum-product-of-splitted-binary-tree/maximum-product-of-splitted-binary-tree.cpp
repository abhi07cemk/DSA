class Solution {
public:
    long long totalSum = 0;
    long long bestProduct = 0;
    static const int MOD = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        totalSum = treeSum(root);
        findMax(root);
        return bestProduct % MOD;
    }

    long long treeSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + treeSum(node->left) + treeSum(node->right);
    }

    long long findMax(TreeNode* node) {
        if (!node) return 0;

        long long left = findMax(node->left);
        long long right = findMax(node->right);

        long long subtreeSum = node->val + left + right;
        long long product = subtreeSum * (totalSum - subtreeSum);

        bestProduct = max(bestProduct, product);
        return subtreeSum;
    }
};
