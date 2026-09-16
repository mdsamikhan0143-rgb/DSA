class Solution {
public:
    string robotWithString(string s) {
        vector<int> frequency(26, 0);

        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        stack<char> t;
        string answer = "";
        int smallest = 0;

        for (char ch : s) {
            t.push(ch);
            frequency[ch - 'a']--;

            // Find the smallest character still unread.
            while (smallest < 26 && frequency[smallest] == 0) {
                smallest++;
            }

            // If nothing remains unread, pop everything.
            while (!t.empty() &&
                   (smallest == 26 || t.top() - 'a' <= smallest)) {
                answer += t.top();
                t.pop();
            }
        }

        return answer;
    }
};
