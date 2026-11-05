class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' ||
               ch == 'O' || ch == 'U';
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // Step 1: Collect vowels
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }

        // Step 2: Sort vowels in ASCII order
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace vowels in the original string
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};