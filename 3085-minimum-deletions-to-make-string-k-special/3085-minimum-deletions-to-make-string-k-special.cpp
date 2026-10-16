class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26] = {0};

        for (char c : word) {
            freq[c - 'a']++;
        }

        int ans = word.size();

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            int del = 0;

            for (int j = 0; j < 26; j++) {
                if (freq[j] == 0) continue;

                if (freq[j] < freq[i]) {
                    del += freq[j];
                }
                else if (freq[j] > freq[i] + k) {
                    del += freq[j] - (freq[i] + k);
                }
            }

            ans = min(ans, del);
        }

        return ans;
    }
};