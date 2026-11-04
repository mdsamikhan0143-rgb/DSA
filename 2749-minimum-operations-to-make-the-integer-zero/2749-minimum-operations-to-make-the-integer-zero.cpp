
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = (long long)num1 - (long long)k * num2;

            if (x >= k && __builtin_popcountll(x) <= k)
                return k;
        }

        return -1;
    }
};
