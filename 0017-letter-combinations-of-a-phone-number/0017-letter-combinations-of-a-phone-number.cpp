class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        solve(digits, 0, "", mp, ans);

        return ans;
    }

    void solve(string digits, int index, string s,
               vector<string>& mp, vector<string>& ans) {
        if (index == digits.length()) {
            ans.push_back(s);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            solve(digits, index + 1, s + ch, mp, ans);
        }
    }
};