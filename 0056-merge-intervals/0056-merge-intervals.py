class Solution:
    def merge(self, intervals):
        # Step 1: Sort intervals by start time
        intervals.sort(key=lambda x: x[0])

        merged = []

        # Step 2: Traverse intervals
        for interval in intervals:
            if not merged or merged[-1][1] < interval[0]:
                # No overlap
                merged.append(interval)
            else:
                # Overlap -> merge
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged