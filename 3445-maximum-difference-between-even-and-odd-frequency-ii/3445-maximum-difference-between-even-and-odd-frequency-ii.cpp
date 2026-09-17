class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int answer = INT_MIN;

        // Collect the different characters present in s
        vector<char> chars;
        bool seen[256] = {};

        for (unsigned char ch : s) {
            if (!seen[ch]) {
                seen[ch] = true;
                chars.push_back(ch);
            }
        }

        for (char a : chars) {
            for (char b : chars) {
                if (a == b) continue;

                vector<int> A(n + 1, 0), B(n + 1, 0);

                for (int i = 0; i < n; i++) {
                    A[i + 1] = A[i] + (s[i] == a);
                    B[i + 1] = B[i] + (s[i] == b);
                }

                int best[2][2] = {
                    {INT_MAX, INT_MAX},
                    {INT_MAX, INT_MAX}
                };

                int left = 0;

                for (int right = k; right <= n; right++) {
                    // Register starts that give length >= k
                    // and at least two occurrences of b
                    while (left <= right - k &&
                           B[right] - B[left] >= 2) {

                        int parityA = A[left] % 2;
                        int parityB = B[left] % 2;

                        best[parityA][parityB] =
                            min(best[parityA][parityB],
                                A[left] - B[left]);

                        left++;
                    }

                    // Opposite parity for a gives an odd frequency.
                    // Same parity for b gives an even frequency.
                    int needA = 1 - (A[right] % 2);
                    int needB = B[right] % 2;

                    if (best[needA][needB] != INT_MAX) {
                        int diff = A[right] - B[right]
                                   - best[needA][needB];

                        answer = max(answer, diff);
                    }
                }
            }
        }

        return answer;
    }
};