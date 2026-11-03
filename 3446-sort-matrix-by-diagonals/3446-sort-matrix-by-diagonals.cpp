
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Bottom-left triangle (including main diagonal)
        for (int i = 0; i < n; i++) {
            vector<int> temp;

            int r = i, c = 0;

            while (r < n && c < n) {
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }

            sort(temp.begin(), temp.end(), greater<int>());

            r = i;
            c = 0;

            for (int j = 0; j < temp.size(); j++) {
                grid[r][c] = temp[j];
                r++;
                c++;
            }
        }

        // Top-right triangle
        for (int j = 1; j < n; j++) {
            vector<int> temp;

            int r = 0, c = j;

            while (r < n && c < n) {
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }

            sort(temp.begin(), temp.end());

            r = 0;
            c = j;

            for (int k = 0; k < temp.size(); k++) {
                grid[r][c] = temp[k];
                r++;
                c++;
            }
        }

        return grid;
    }
};
