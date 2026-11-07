class Solution {
public:

    string toLower(string s) {
        for (char &ch : s) {
            ch = tolower(ch);
        }
        return s;
    }

    string maskVowels(string s) {
        for (char &ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u') {
                ch = '*';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {

        unordered_set<string> exact;
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelMap;

        // Store words from wordlist
        for (string word : wordlist) {

            exact.insert(word);

            string lower = toLower(word);

            if (!caseInsensitive.count(lower)) {
                caseInsensitive[lower] = word;
            }

            string masked = maskVowels(lower);

            if (!vowelMap.count(masked)) {
                vowelMap[masked] = word;
            }
        }

        vector<string> ans;

        // Process queries
        for (string query : queries) {

            // 1. Exact match
            if (exact.count(query)) {
                ans.push_back(query);
                continue;
            }

            string lower = toLower(query);

            // 2. Case-insensitive match
            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            // 3. Vowel error match
            string masked = maskVowels(lower);

            if (vowelMap.count(masked)) {
                ans.push_back(vowelMap[masked]);
            }
            else {
                ans.push_back("");
            }
        }

        return ans;
    }
};