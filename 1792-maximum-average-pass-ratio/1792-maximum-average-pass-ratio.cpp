
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<pair<double, int>> pq;

        int n = classes.size();

        for (int i = 0; i < n; i++) {
            double pass = classes[i][0];
            double total = classes[i][1];

            double gain = (pass + 1) / (total + 1) - pass / total;

            pq.push({gain, i});
        }

        while (extraStudents--) {
            auto [gain, i] = pq.top();
            pq.pop();

            classes[i][0]++;
            classes[i][1]++;

            double pass = classes[i][0];
            double total = classes[i][1];

            double newGain = (pass + 1) / (total + 1) - pass / total;

            pq.push({newGain, i});
        }

        double sum = 0;

        for (auto &c : classes) {
            sum += (double)c[0] / c[1];
        }

        return sum / n;
    }
};
