class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        """
        Problem: 0220 - Contains Duplicate III
        
        Find if there exists a pair (i,j) where:
        - i != j
        - abs(i - j) <= indexDiff  
        - abs(nums[i] - nums[j]) <= valueDiff
        
        Use bucket sort approach: divide value space into buckets of size (valueDiff + 1).
        Two values in same bucket always satisfy valueDiff constraint.
        Adjacent buckets might also contain valid values.
        
        Time complexity: O(n) where n is the length of nums.
        Space complexity: O(min(n, indexDiff)) for the buckets dictionary.
        """
        # Edge case: valueDiff is negative.
        if valueDiff < 0:
            return False
        
        # Dictionary to store bucket_id -> value mapping.
        # We only keep one value per bucket since two values in same bucket = valid pair.
        buckets = {}
        
        # Bucket width is valueDiff + 1 to ensure values in same bucket differ by at most valueDiff.
        # Example: valueDiff = 3, bucket width = 4, so [0,1,2,3] are in bucket 0.
        bucket_width = valueDiff + 1
        
        for i in range(len(nums)):
            # Calculate which bucket nums[i] belongs to.
            # For negative numbers, we shift to ensure proper bucketing.
            bucket_id = nums[i] // bucket_width
            
            # Check if current bucket already has an element.
            # If yes, they're within valueDiff (same bucket property).
            if bucket_id in buckets:
                return True
            
            # Check left adjacent bucket for values within valueDiff.
            # Element in left bucket could be at most valueDiff away.
            if bucket_id - 1 in buckets:
                # Check if the actual difference is within valueDiff.
                if abs(nums[i] - buckets[bucket_id - 1]) <= valueDiff:
                    return True
            
            # Check right adjacent bucket for values within valueDiff.
            # Element in right bucket could be at most valueDiff away.
            if bucket_id + 1 in buckets:
                # Check if the actual difference is within valueDiff.
                if abs(nums[i] - buckets[bucket_id + 1]) <= valueDiff:
                    return True
            
            # Add current element to its bucket.
            buckets[bucket_id] = nums[i]
            
            # Remove element that is outside the index window.
            # If we've processed more than indexDiff elements, remove the oldest.
            if i >= indexDiff:
                # Calculate bucket id of element to remove.
                old_bucket_id = nums[i - indexDiff] // bucket_width
                # Remove it from buckets.
                del buckets[old_bucket_id]
        
        # No valid pair found.
        return False
