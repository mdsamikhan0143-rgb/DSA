
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;

        for (string word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (mp[rev] > 0) {
                ans += 4;
                mp[rev]--;
            } else {
                mp[word]++;
            }
        }

        for (auto it : mp) {
            if (it.first[0] == it.first[1] && it.second > 0) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};
