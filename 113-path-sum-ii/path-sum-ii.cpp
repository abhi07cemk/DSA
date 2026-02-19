class Solution {
public:
    void dfs(TreeNode* root, int targetSum, 
             vector<int>& path, 
             vector<vector<int>>& result) {
        
        if (root == NULL) return;
        
        // Add current node to path
        path.push_back(root->val);
        
        // If leaf node and sum matches
        if (root->left == NULL && root->right == NULL 
            && targetSum == root->val) {
            result.push_back(path);
        }
        
        // Recurse left and right
        dfs(root->left, targetSum - root->val, path, result);
        dfs(root->right, targetSum - root->val, path, result);
        
        // Backtrack
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(root, targetSum, path, result);
        
        return result;
    }
};
