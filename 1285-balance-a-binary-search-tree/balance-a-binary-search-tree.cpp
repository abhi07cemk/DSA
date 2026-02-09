class Solution {
public:
    // Step 1: Inorder traversal to get sorted elements
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) return;

        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    // Step 2: Build balanced BST from sorted array
    TreeNode* buildBST(vector<int>& nodes, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);

        root->left = buildBST(nodes, start, mid - 1);
        root->right = buildBST(nodes, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;

        inorder(root, nodes);                 
        return buildBST(nodes, 0, nodes.size() - 1); 
    }
};
