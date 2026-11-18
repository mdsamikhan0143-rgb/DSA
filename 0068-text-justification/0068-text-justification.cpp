class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Step 1: Greedily select words for current line
            while (j < n && letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Step 2: Last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += " ";
                    }
                }

                // Add remaining spaces at the end
                line += string(maxWidth - line.size(), ' ');
            }

            // Step 3: Fully justify the line
            else {
                int spaces = maxWidth - letters;
                int eachSpace = spaces / gaps;
                int extraSpace = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int count = eachSpace;

                        // Give extra spaces to left slots
                        if (extraSpace > 0) {
                            count++;
                            extraSpace--;
                        }

                        line += string(count, ' ');
                    }
                }
            }

            ans.push_back(line);

            // Move to next line
            i = j;
        }

        return ans;
    }
};