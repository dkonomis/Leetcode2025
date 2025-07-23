class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        """
        Problem: 0219 - Contains Duplicate II
        
        Check if array contains duplicates within k distance.
        Use a sliding window with a hash set to track elements within k indices.
        Remove elements that are more than k indices away.
        
        Time complexity: O(n) where n is the length of the array.
        Space complexity: O(min(n, k)) for the hash set.
        """
        window = set()
        
        # Process each element in the array.
        for i in range(len(nums)):
            # If current number is already in window, found duplicate within k.
            if nums[i] in window:
                return True
            
            # Add current number to window.
            window.add(nums[i])
            
            # Remove element that is more than k indices away.
            if len(window) > k:
                window.remove(nums[i - k])
        
        # No duplicates found within k distance.
        return False
