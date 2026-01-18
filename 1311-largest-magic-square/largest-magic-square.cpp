class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix sums
        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        int ans = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int size = 2; i + size <= m && j + size <= n; size++) {

                    int target = row[i][j + size] - row[i][j];
                    bool ok = true;

                    // Check rows
                    for (int r = i; r < i + size; r++) {
                        if (row[r][j + size] - row[r][j] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check columns
                    for (int c = j; c < j + size && ok; c++) {
                        if (col[i + size][c] - col[i][c] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check diagonals
                    int diag1 = 0, diag2 = 0;
                    for (int k = 0; k < size; k++) {
                        diag1 += grid[i + k][j + k];
                        diag2 += grid[i + k][j + size - 1 - k];
                    }

                    if (ok && diag1 == target && diag2 == target) {
                        ans = max(ans, size);
                    }
                }
            }
        }

        return ans;
    }
};
