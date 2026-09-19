class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Find the row containing the middle column's maximum.
            int row = 0;
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[row][mid]) {
                    row = i;
                }
            }

            int left = (mid > 0) ? mat[row][mid - 1] : -1;
            int right = (mid < n - 1) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }

            if (left > mat[row][mid]) {
                high = mid - 1;  // Search the left half.
            } else {
                low = mid + 1;   // Search the right half.
            }
        }

        return {-1, -1};
    }
};
