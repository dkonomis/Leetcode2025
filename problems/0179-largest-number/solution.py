from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        """
        Problem: 0179 - Largest Number
        
        Given a list of non-negative integers, arrange them to form the largest number.
        We need to sort the numbers based on which arrangement produces a larger result
        when concatenated.
        
        Approach:
        - Convert all numbers to strings for comparison
        - Define a custom comparator that compares str(a) + str(b) vs str(b) + str(a)
        - Sort using this comparator to get the optimal ordering
        - Handle edge case where all numbers are 0
        
        Time complexity: O(n log n * k) where k is the average string length.
        Space complexity: O(n) for the string conversions.
        """
        def compare(x, y):
            # Compare which order produces a larger number.
            if x + y > y + x:
                return -1  # x should come before y.
            elif x + y < y + x:
                return 1   # y should come before x.
            else:
                return 0   # They are equal in this context.
        
        # Convert all numbers to strings for comparison.
        num_strings = [str(num) for num in nums]
        
        # Sort using the custom comparator.
        num_strings.sort(key=cmp_to_key(compare))
        
        # Join all strings to form the result.
        res = ''.join(num_strings)
        
        # Handle edge case where the result is all zeros.
        if res[0] == '0':
            return '0'
        
        return res
