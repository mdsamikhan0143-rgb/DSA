class Solution {
public:
    /*
    Returns true if the target
    exists anywhere in the matrix.
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Stop early if the matrix has no usable cells.
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
 
        // These store the matrix dimensions for boundary checks.
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();
 
        // Start from the top-right corner to remove one row or column each step.
        int row = 0;
        int col = cols - 1;
 
        while (row < rows && col >= 0) {
            // Read the current corner value of the remaining search area.
            int current = matrix[row][col];
 
            // Return immediately because the target is found here.
            if (current == target) {
                return true;
            }
 
            // Move left because everything below this value is even larger.
            if (current > target) {
                col--;
            } else {
                // Move down because everything left of this value is even smaller.
                row++;
            }
        }
 
        return false;
    }
};