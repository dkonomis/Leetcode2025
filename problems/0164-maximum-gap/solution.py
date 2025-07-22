class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        """
        0164 - Maximum Gap
        
        Find maximum difference between successive elements in sorted form.
        Must solve in O(n) time and O(n) space.
        
        Approach:
        - Use bucket sort concept with pigeonhole principle
        - Create n-1 buckets with gap size = (max-min)/(n-1)
        - Maximum gap must be between buckets, not within buckets
        - Only store min/max for each bucket to save space
        - Find max difference between max of one bucket and min of next non-empty bucket
        
        Time complexity: O(n).
        Space complexity: O(n).
        """
        if len(nums) < 2:
            return 0
        
        n = len(nums)
        min_val, max_val = min(nums), max(nums)
        
        # If all elements are the same, gap is 0.
        if min_val == max_val:
            return 0
        
        # Calculate bucket size using ceiling division.
        bucket_size = max(1, (max_val - min_val) // (n - 1))
        bucket_count = (max_val - min_val) // bucket_size + 1
        
        # Initialize buckets to store min and max values.
        buckets = [[float('inf'), float('-inf')] for _ in range(bucket_count)]
        
        # Place each number into appropriate bucket.
        for num in nums:
            idx = (num - min_val) // bucket_size
            buckets[idx][0] = min(buckets[idx][0], num)  # Update min.
            buckets[idx][1] = max(buckets[idx][1], num)  # Update max.
        
        # Find maximum gap between buckets.
        res = 0
        prev_max = min_val
        
        for bucket_min, bucket_max in buckets:
            # Skip empty buckets.
            if bucket_min == float('inf'):
                continue
            
            # Gap between previous bucket's max and current bucket's min.
            res = max(res, bucket_min - prev_max)
            prev_max = bucket_max
        
        return res
