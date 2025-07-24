class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Problem: 0238 - Product of Array Except Self
        
        Calculate product of all elements except self without division.
        Use two passes: left-to-right for prefix products, right-to-left for suffix products.
        First pass: res[i] = product of all elements to the left of i.
        Second pass: multiply by product of all elements to the right of i.
        
        Time complexity: O(n) with two passes through the array.
        Space complexity: O(1) excluding the output array.
        """
        n = len(nums)
        res = [1] * n
        
        # First pass: calculate prefix products.
        # res[i] will contain product of all elements before index i.
        for i in range(1, n):
            res[i] = res[i - 1] * nums[i - 1]
        
        # Second pass: multiply by suffix products.
        # Use a running product from right to left.
        right_product = 1
        for i in range(n - 1, -1, -1):
            # Multiply current result by product of elements to the right.
            res[i] *= right_product
            # Update right product for next iteration.
            right_product *= nums[i]
        
        return res
