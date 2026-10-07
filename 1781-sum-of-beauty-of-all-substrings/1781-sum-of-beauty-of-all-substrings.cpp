class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            int freq[26] = {0};

            for (int j = i; j < s.length(); j++) {

                freq[s[j] - 'a']++;

                int maxi = 0;
                int mini = 1000000;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                ans += maxi - mini;
            }
        }

        return ans;
    }
};