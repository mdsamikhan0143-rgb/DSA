class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {

        set<string> visited;
        queue<string> q;

        string ans = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            // Update smallest string
            ans = min(ans, curr);

            // Operation 1: Add a to odd indices
            string add = curr;

            for (int i = 1; i < add.size(); i += 2) {
                add[i] = '0' + (add[i] - '0' + a) % 10;
            }

            if (!visited.count(add)) {
                visited.insert(add);
                q.push(add);
            }

            // Operation 2: Rotate right by b positions
            string rotate = curr;

            int n = rotate.size();

            rotate = rotate.substr(n - b) + rotate.substr(0, n - b);

            if (!visited.count(rotate)) {
                visited.insert(rotate);
                q.push(rotate);
            }
        }

        return ans;
    }
};