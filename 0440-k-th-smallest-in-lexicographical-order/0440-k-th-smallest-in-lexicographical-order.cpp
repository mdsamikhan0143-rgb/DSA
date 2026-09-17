class Solution {
public:
    long long countSteps(int n, long long first, long long next) {
        long long steps = 0;

        while (first <= n) {
            steps += min((long long)n + 1, next) - first;
            first *= 10;
            next *= 10;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        int current = 1;
        k--;  // We are already at the first number: 1

        while (k > 0) {
            long long steps = countSteps(n, current, current + 1);

            if (steps <= k) {
                // Skip this entire prefix group
                current++;
                k -= steps;
            } else {
                // The answer is inside this prefix group
                current *= 10;
                k--;
            }
        }

        return current;
    }
};