class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        int total = 0;

        // Calculate complete weeks
        for (int i = 0; i < weeks; i++) {
            total += (i + 1) * 7 + 21;
        }

        // Calculate remaining days
        for (int i = 0; i < days; i++) {
            total += weeks + i + 1;
        }

        return total;
    }
};