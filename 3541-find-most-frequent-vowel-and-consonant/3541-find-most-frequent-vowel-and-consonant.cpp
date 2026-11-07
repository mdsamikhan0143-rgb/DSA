class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        // Find maximum vowel and consonant frequency
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;

            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            }
            else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        return maxVowel + maxConsonant;
    }
};