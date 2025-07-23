class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        Problem: 0217 - Contains Duplicate
        
        Check if array contains any duplicates using a hash set.
        Add each element to set and return true if we find a duplicate.
        
        Time complexity: O(n) where n is the length of the array.
        Space complexity: O(n) for the hash set.
        """
        seen = set()
        
        # Check each number in the array.
        for num in nums:
            # If number already in set, we found a duplicate.
            if num in seen:
                return True
            # Add number to set.
            seen.add(num)
        
        # No duplicates found.
        return False
