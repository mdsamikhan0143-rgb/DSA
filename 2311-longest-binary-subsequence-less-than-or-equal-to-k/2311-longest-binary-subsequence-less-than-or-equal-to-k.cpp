
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int ans = 0;
        long long value = 0;
        int power = 0;

        // Take bits from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                ans++;
            } 
            else if (power < 63) {
                long long add = 1LL << power;

                if (value + add <= k) {
                    value += add;
                    ans++;
                }
            }

            if (s[i] == '1' && power < 63)
                power++;
            else if (s[i] == '0' && power < 63)
                power++;
        }

        return ans;
    }
};
