
class Solution {
public:
    bool isValid(string s, string seq, int k) {
        int j = 0;
        int count = 0;

        for (char c : s) {
            if (c == seq[j]) {
                j++;

                if (j == seq.size()) {
                    j = 0;
                    count++;

                    if (count == k)
                        return true;
                }
            }
        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        q.push("");

        string ans = "";

        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (char c = 'z'; c >= 'a'; c--) {
                if (freq[c - 'a'] < k)
                    continue;

                string next = curr + c;

                if (isValid(s, next, k)) {
                    if (next.size() > ans.size() ||
                        (next.size() == ans.size() && next > ans)) {
                        ans = next;
                    }

                    q.push(next);
                }
            }
        }

        return ans;
    }
};
