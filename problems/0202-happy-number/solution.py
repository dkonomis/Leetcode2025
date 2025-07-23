class Solution:
    def isHappy(self, n: int) -> bool:
        """
        Problem: 0202 - Happy Number
        
        Determine if a number is happy by repeatedly replacing it with the sum
        of squares of its digits until it reaches 1 or enters a cycle.
        
        Approach: Use a set to track seen numbers. If we encounter a number
        we've seen before, we're in a cycle. If we reach 1, it's happy.
        
        Time complexity: O(log n) on average for happy numbers.
        Space complexity: O(log n) for the set storing seen numbers.
        """
        def get_sum_of_squares(num):
            """Calculate sum of squares of digits."""
            total = 0
            while num > 0:
                digit = num % 10  # Get last digit.
                total += digit * digit  # Add square of digit.
                num //= 10  # Remove last digit.
            return total
        
        seen = set()
        
        # Continue until we reach 1 or detect a cycle.
        while n != 1 and n not in seen:
            seen.add(n)  # Mark current number as seen.
            n = get_sum_of_squares(n)  # Replace with sum of squares.
        
        # If we exited because n == 1, it's happy. Otherwise, we found a cycle.
        return n == 1
