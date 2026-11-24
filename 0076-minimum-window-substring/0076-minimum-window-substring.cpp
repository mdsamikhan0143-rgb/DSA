class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int required = 0;

        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                window[ch]--;

                if (need[ch] > 0 && window[ch] < need[ch]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};