
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int cnt = 0;

        for (int i = operations.size() - 1; i >= 0; i--) {
            long long len = 1LL;

            for (int j = 0; j < i && len < k; j++)
                len *= 2;

            if (k > len) {
                k -= len;

                if (operations[i] == 1)
                    cnt++;
            }
        }

        return 'a' + (cnt % 26);
    }
};
