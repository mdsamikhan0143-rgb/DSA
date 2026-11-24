class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int idx) {

        // Word completely found
        if (idx == word.size()) {
            return true;
        }

        // Boundary and character checking
        if (i < 0 || j < 0 ||
            i >= board.size() ||
            j >= board[0].size() ||
            board[i][j] != word[idx]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore four directions
        bool found =
            dfs(board, word, i + 1, j, idx + 1) ||
            dfs(board, word, i - 1, j, idx + 1) ||
            dfs(board, word, i, j + 1, idx + 1) ||
            dfs(board, word, i, j - 1, idx + 1);

        // Backtracking: restore original character
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};