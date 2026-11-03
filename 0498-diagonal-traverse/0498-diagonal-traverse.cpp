
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        int row = 0, col = 0;
        int dir = 1;

        while (ans.size() < m * n) {
            ans.push_back(mat[row][col]);

            if (dir == 1) {
                if (col == n - 1) {
                    row++;
                    dir = -1;
                }
                else if (row == 0) {
                    col++;
                    dir = -1;
                }
                else {
                    row--;
                    col++;
                }
            }
            else {
                if (row == m - 1) {
                    col++;
                    dir = 1;
                }
                else if (col == 0) {
                    row++;
                    dir = 1;
                }
                else {
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};
