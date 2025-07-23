import random

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        Problem: 0215 - Kth Largest Element in an Array
        
        Use QuickSelect with three-way partitioning to find kth largest element.
        We convert kth largest to (n-k+1)th smallest and solve accordingly.
        This handles duplicates efficiently and avoids worst-case scenarios.
        
        Time complexity: O(n) average case, O(n^2) worst case.
        Space complexity: O(n) for the partition arrays.
        """
        # Convert kth largest to (n-k+1)th smallest.
        n = len(nums)
        k_smallest = n - k + 1
        
        def quick_select(nums: List[int], k: int) -> int:
            # Choose random pivot.
            pivot = random.choice(nums)
            left, mid, right = [], [], []
            
            # Three-way partition: elements < pivot, = pivot, > pivot.
            for num in nums:
                if num < pivot:
                    left.append(num)
                elif num > pivot:
                    right.append(num)
                else:
                    mid.append(num)
            
            # If k-th smallest is in left (smaller elements).
            if k <= len(left):
                return quick_select(left, k)
            
            # If k-th smallest is in right (larger elements).
            if len(left) + len(mid) < k:
                return quick_select(right, k - len(left) - len(mid))
            
            # k-th smallest is the pivot.
            return pivot
        
        return quick_select(nums, k_smallest)
