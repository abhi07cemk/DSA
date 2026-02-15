class Solution {
public:
    
    void solve(int col,
               vector<string> &board,
               vector<vector<string>> &ans,
               vector<int> &leftRow,
               vector<int> &upperDiagonal,
               vector<int> &lowerDiagonal,
               int n) 
    {
        // Base case
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            
            // Check if safe using hashing (O(1))
            if(leftRow[row] == 0 && 
               lowerDiagonal[row + col] == 0 &&
               upperDiagonal[n - 1 + col - row] == 0) {
                
                // Place queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                
                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }
        
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2*n - 1, 0);
        vector<int> lowerDiagonal(2*n - 1, 0);
        
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        
        return ans;
    }
};
