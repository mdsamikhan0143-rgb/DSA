class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0, south = 0, east = 0, west = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') north++;
            else if (s[i] == 'S') south++;
            else if (s[i] == 'E') east++;
            else west++;

            int dist = abs(north - south) + abs(east - west);
            int steps = i + 1;

            ans = max(ans, min(steps, dist + 2 * k));
        }

        return ans;
    }
};