
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        int ans = -1;

        for (auto it : freq) {
            if (it.first == it.second) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};
