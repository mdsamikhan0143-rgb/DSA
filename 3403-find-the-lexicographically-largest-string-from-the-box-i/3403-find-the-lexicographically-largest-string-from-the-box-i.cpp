class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        int n = word.size();
        int maxLength = n - numFriends + 1;
        string answer = "";

        for (int i = 0; i < n; i++) {
            string current = word.substr(i, maxLength);

            if (current > answer) {
                answer = current;
            }
        }

        return answer;
    }
};