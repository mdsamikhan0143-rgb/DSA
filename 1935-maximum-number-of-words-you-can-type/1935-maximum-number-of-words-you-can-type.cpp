class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        bool broken[26] = {false};

        // Mark broken letters
        for (char ch : brokenLetters) {
            broken[ch - 'a'] = true;
        }

        int count = 0;
        bool valid = true;

        // Check each character
        for (char ch : text) {

            if (ch == ' ') {
                if (valid) {
                    count++;
                }
                valid = true;
            }
            else if (broken[ch - 'a']) {
                valid = false;
            }
        }

        // Check the last word
        if (valid) {
            count++;
        }

        return count;
    }
};