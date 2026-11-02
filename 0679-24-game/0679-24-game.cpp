
class Solution {
public:
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {

                if (i == j) continue;

                vector<double> temp;

                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        temp.push_back(nums[k]);
                    }
                }

                double a = nums[i];
                double b = nums[j];

                vector<double> results = {
                    a + b,
                    a - b,
                    a * b
                };

                if (abs(b) > 1e-6) {
                    results.push_back(a / b);
                }

                for (double val : results) {
                    temp.push_back(val);

                    if (solve(temp)) {
                        return true;
                    }

                    temp.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;

        for (int x : cards) {
            nums.push_back(x);
        }

        return solve(nums);
    }
};
