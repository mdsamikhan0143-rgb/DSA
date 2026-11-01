class Solution {
public:
    vector<int> seg;

    void build(int node, int start, int end, vector<int>& baskets) {
        if (start == end) {
            seg[node] = baskets[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node, start, mid, baskets);
        build(2 * node + 1, mid + 1, end, baskets);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int start, int end, int x) {
        if (seg[node] < x)
            return -1;

        if (start == end)
            return start;

        int mid = start + (end - start) / 2;

        if (seg[2 * node] >= x)
            return query(2 * node, start, mid, x);

        return query(2 * node + 1, mid + 1, end, x);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            seg[node] = -1;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx);
        else
            update(2 * node + 1, mid + 1, end, idx);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, baskets);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int idx = query(1, 0, n - 1, fruits[i]);

            if (idx == -1) {
                ans++;
            } else {
                update(1, 0, n - 1, idx);
            }
        }

        return ans;
    }
};
