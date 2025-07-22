class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        """
        0166 - Fraction to Recurring Decimal
        
        Convert fraction to decimal string format, with repeating parts in parentheses.
        Use long division simulation with remainder tracking to detect cycles.
        
        Approach:
        - Handle sign and edge cases first
        - Calculate integer part using division
        - For decimal part, simulate long division step by step
        - Use HashMap to track remainder positions for cycle detection
        - When remainder repeats, insert parentheses around repeating sequence
        
        Time complexity: O(denominator).
        Space complexity: O(denominator).
        """
        if numerator == 0:
            return "0"
        
        res = []
        
        # Handle negative sign.
        if (numerator < 0) ^ (denominator < 0):
            res.append("-")
        
        # Work with absolute values to avoid overflow issues.
        numerator, denominator = abs(numerator), abs(denominator)
        
        # Calculate integer part.
        integer_part = numerator // denominator
        res.append(str(integer_part))
        
        # Calculate remainder for decimal part.
        remainder = numerator % denominator
        
        # If no remainder, return integer result.
        if remainder == 0:
            return "".join(res)
        
        # Add decimal point.
        res.append(".")
        
        # Track remainder positions to detect repeating cycles.
        remainder_positions = {}
        
        # Simulate long division for decimal part.
        while remainder != 0:
            # If we've seen this remainder before, we found a cycle.
            if remainder in remainder_positions:
                # Insert opening parenthesis at cycle start.
                cycle_start = remainder_positions[remainder]
                res.insert(cycle_start, "(")
                # Add closing parenthesis at end.
                res.append(")")
                break
            
            # Record current remainder position.
            remainder_positions[remainder] = len(res)
            
            # Perform long division step:
            # Step 1: "Bring down a zero" - multiply remainder by 10.
            # This simulates adding a decimal place in manual division.
            remainder *= 10
            
            # Step 2: Divide - how many times does denominator go into new remainder?
            # This gives us the next digit in our decimal expansion.
            digit = remainder // denominator
            res.append(str(digit))
            
            # Step 3: Calculate new remainder for next iteration.
            # This is what's "left over" after the division step.
            remainder = remainder % denominator
            # If remainder becomes 0, division terminates (no more decimal digits).
            # If remainder repeats a previous value, we found the cycle!
        
        return "".join(res)
