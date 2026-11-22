class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool solve(string &s1, string &s2, int i, int j, int len) {

        // If both substrings are equal
        if(s1.substr(i, len) == s2.substr(j, len)) {
            return true;
        }

        // If result is already calculated
        if(dp[i][j][len] != -1) {
            return dp[i][j][len];
        }

        // Check whether both substrings have same characters
        int freq[26] = {0};

        for(int k = 0; k < len; k++) {
            freq[s1[i+k] - 'a']++;
            freq[s2[j+k] - 'a']--;
        }

        for(int k = 0; k < 26; k++) {
            if(freq[k] != 0) {
                return dp[i][j][len] = false;
            }
        }

        // Try every possible split
        for(int k = 1; k < len; k++) {

            // Case 1: Without swapping
            bool withoutSwap =
                solve(s1, s2, i, j, k) &&
                solve(s1, s2, i+k, j+k, len-k);

            // Case 2: With swapping
            bool withSwap =
                solve(s1, s2, i, j+len-k, k) &&
                solve(s1, s2, i+k, j, len-k);

            if(withoutSwap || withSwap) {
                return dp[i][j][len] = true;
            }
        }

        return dp[i][j][len] = false;
    }

    bool isScramble(string s1, string s2) {

        int n = s1.size();

        if(n != s2.size()) {
            return false;
        }

        dp.assign(n, vector<vector<int>>(
            n, vector<int>(n+1, -1)
        ));

        return solve(s1, s2, 0, 0, n);
    }
};