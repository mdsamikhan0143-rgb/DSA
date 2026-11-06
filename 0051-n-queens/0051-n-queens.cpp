class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        function<void(int)> backtrack = [&](int row) {
            // All queens are placed successfully
            if (row == n) {
                ans.push_back(board);
                return;
            }

            for (int c = 0; c < n; c++) {

                // Check whether this position is safe
                if (col[c] || diag1[row - c + n - 1] ||
                    diag2[row + c]) {
                    continue;
                }

                // Place queen
                board[row][c] = 'Q';
                col[c] = 1;
                diag1[row - c + n - 1] = 1;
                diag2[row + c] = 1;

                // Move to the next row
                backtrack(row + 1);

                // Backtrack: remove queen
                board[row][c] = '.';
                col[c] = 0;
                diag1[row - c + n - 1] = 0;
                diag2[row + c] = 0;
            }
        };

        backtrack(0);

        return ans;
    }
};