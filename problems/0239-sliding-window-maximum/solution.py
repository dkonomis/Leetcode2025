from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        """
        Problem: 0239 - Sliding Window Maximum
        
        Find maximum in each sliding window of size k.
        Use a deque to maintain indices of elements in decreasing order.
        The front of deque always contains index of the maximum element.
        Clean deque by removing indices outside window and smaller elements.
        
        Time complexity: O(n) where n is the length of nums.
        Space complexity: O(k) for the deque.
        """
        # Base cases.
        n = len(nums)
        # Empty array or k is 0.
        if n * k == 0:
            return []
        # Window size 1 means every element is its own maximum.
        if k == 1:
            return nums
        
        def clean_deque(i):
            # Remove indexes of elements not from sliding window.
            # If leftmost index is now outside the window, remove it.
            if deq and deq[0] == i - k:
                deq.popleft()
            
            # Remove from deq indexes of all elements.
            # which are smaller than current element nums[i].
            # These elements can never be maximum in any future window.
            while deq and nums[i] > nums[deq[-1]]:
                deq.pop()
        
        # Initialize deque and output.
        deq = deque()
        
        # Process first window separately.
        for i in range(k):
            # Clean deque and add current index.
            clean_deque(i)
            deq.append(i)
        
        # First window's maximum is at front of deque.
        output = [nums[deq[0]]]
        
        # Build output for remaining windows.
        for i in range(k, n):
            # Clean deque for new element at index i.
            clean_deque(i)
            # Add current index to deque.
            deq.append(i)
            # Front of deque has the maximum for current window.
            output.append(nums[deq[0]])
        
        return output
