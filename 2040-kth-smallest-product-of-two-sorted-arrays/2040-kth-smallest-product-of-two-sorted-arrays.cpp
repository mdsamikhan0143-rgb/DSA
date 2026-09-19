class Solution {
public:
    long long countProducts(vector<int>& nums1,
                            vector<int>& nums2,
                            long long target) {
        long long count = 0;
        int m = nums2.size();

        for (int a : nums1) {
            if (a == 0) {
                // Every product is 0.
                if (target >= 0) count += m;
                continue;
            }

            int left = 0, right = m;

            if (a > 0) {
                // Products increase as nums2 increases.
                // Find the first product > target.
                while (left < right) {
                    int mid = left + (right - left) / 2;

                    if (1LL * a * nums2[mid] <= target) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }

                count += left;
            } else {
                // Products decrease as nums2 increases.
                // Find the first product <= target.
                while (left < right) {
                    int mid = left + (right - left) / 2;

                    if (1LL * a * nums2[mid] <= target) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }

                count += m - left;
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1,
                                vector<int>& nums2,
                                long long k) {
        // Minimum and maximum products occur at endpoints.
        long long p1 = 1LL * nums1.front() * nums2.front();
        long long p2 = 1LL * nums1.front() * nums2.back();
        long long p3 = 1LL * nums1.back() * nums2.front();
        long long p4 = 1LL * nums1.back() * nums2.back();

        long long low = min(min(p1, p2), min(p3, p4));
        long long high = max(max(p1, p2), max(p3, p4));

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countProducts(nums1, nums2, mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};