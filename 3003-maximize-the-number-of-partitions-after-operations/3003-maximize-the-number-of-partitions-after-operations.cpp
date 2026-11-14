class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {

        int n = s.size();

        unordered_map<long long, int> dp;

        function<int(int, int, bool)> solve =
        [&](int i, int mask, bool canChange) -> int {

            if (i == n)
                return 0;

            // Create unique key for memoization
            long long key = ((long long)i << 27)
                          | ((long long)canChange << 26)
                          | mask;

            if (dp.count(key))
                return dp[key];

            int ans = 0;

            // Function to process current character
            auto getResult = [&](int bit, bool nextChange) {

                int newMask = mask | bit;

                // More than k distinct characters
                if (__builtin_popcount((unsigned)newMask) > k) {

                    return 1 + solve(
                        i + 1,
                        bit,
                        nextChange
                    );
                }

                return solve(
                    i + 1,
                    newMask,
                    nextChange
                );
            };

            // Case 1: Keep the original character
            int bit = 1 << (s[i] - 'a');

            ans = getResult(bit, canChange);

            // Case 2: Change the current character
            if (canChange) {

                for (int j = 0; j < 26; j++) {

                    int newBit = 1 << j;

                    ans = max(
                        ans,
                        getResult(newBit, false)
                    );
                }
            }

            return dp[key] = ans;
        };

        return solve(0, 0, true) + 1;
    }
};