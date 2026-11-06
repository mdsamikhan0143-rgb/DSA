class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;

        vector<int> col(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        function<void(int)> solve = [&](int row) {

            // All queens are placed successfully
            if (row == n) {
                count++;
                return;
            }

            for (int c = 0; c < n; c++) {

                // Check if the position is safe
                if (col[c] || diag1[row - c + n - 1] ||
                    diag2[row + c]) {
                    continue;
                }

                // Place queen
                col[c] = 1;
                diag1[row - c + n - 1] = 1;
                diag2[row + c] = 1;

                // Move to next row
                solve(row + 1);

                // Backtrack
                col[c] = 0;
                diag1[row - c + n - 1] = 0;
                diag2[row + c] = 0;
            }
        };

        solve(0);

        return count;
    }
};