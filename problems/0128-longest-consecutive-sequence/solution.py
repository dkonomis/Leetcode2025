class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        Problem: 0128 - Longest Consecutive Sequence
        
        Find the length of longest consecutive elements sequence.
        
        Approach:
        1. Use hash set for O(1) lookups.
        2. Only start counting sequences from their beginning.
        3. For each number x, only count if x-1 is not in set.
        4. This ensures each sequence is counted exactly once.
        
        Time complexity: O(n) where n is length of nums.
        Space complexity: O(n) for the hash set.
        """
        if not nums:
            return 0
        
        num_set = set(nums)
        max_length = 0
        
        for num in num_set:
            # Only start a sequence if this is the beginning.
            if num - 1 not in num_set:
                current_num = num
                current_length = 1
                
                # Count consecutive numbers starting from current_num.
                while current_num + 1 in num_set:
                    current_num += 1
                    current_length += 1
                
                # Update maximum length found.
                max_length = max(max_length, current_length)
        
        return max_length
