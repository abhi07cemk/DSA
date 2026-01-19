class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // Build prefix sum matrix
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int low = 0, high = min(m, n), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;  // candidate side length

            if (existsSquare(prefix, m, n, mid, threshold)) {
                ans = mid;       // valid → try bigger
                low = mid + 1;
            } else {
                high = mid - 1;  // too big → try smaller
            }
        }

        return ans;
    }

private:
    bool existsSquare(vector<vector<int>>& prefix, int m, int n,
                      int len, int threshold) {
        if (len == 0) return true;

        for (int i = len; i <= m; i++) {
            for (int j = len; j <= n; j++) {
                int sum = prefix[i][j]
                        - prefix[i - len][j]
                        - prefix[i][j - len]
                        + prefix[i - len][j - len];

                if (sum <= threshold) return true;
            }
        }
        return false;
    }
};
