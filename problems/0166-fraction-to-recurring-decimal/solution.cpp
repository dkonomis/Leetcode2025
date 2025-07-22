class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        /*
        Problem: 0166 - Fraction to Recurring Decimal
        
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
        */
        
        if (numerator == 0) {
            return "0";
        }
        
        string res;
        
        // Handle negative sign.
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }
        
        // Work with absolute values to avoid overflow issues.
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        // Calculate integer part.
        long long integer_part = num / den;
        res += to_string(integer_part);
        
        // Calculate remainder for decimal part.
        long long remainder = num % den;
        
        // If no remainder, return integer result.
        if (remainder == 0) {
            return res;
        }
        
        // Add decimal point.
        res += ".";
        
        // Track remainder positions to detect repeating cycles.
        unordered_map<long long, int> remainder_positions;
        
        // Simulate long division for decimal part.
        while (remainder != 0) {
            // If we've seen this remainder before, we found a cycle.
            if (remainder_positions.count(remainder)) {
                // Insert opening parenthesis at cycle start.
                int cycle_start = remainder_positions[remainder];
                res.insert(cycle_start, "(");
                // Add closing parenthesis at end.
                res += ")";
                break;
            }
            
            // Record current remainder position.
            remainder_positions[remainder] = res.length();
            
            // Perform long division step:
            // Step 1: "Bring down a zero" - multiply remainder by 10.
            // This simulates adding a decimal place in manual division.
            remainder *= 10;
            
            // Step 2: Divide - how many times does denominator go into new remainder?
            // This gives us the next digit in our decimal expansion.
            long long digit = remainder / den;
            res += to_string(digit);
            
            // Step 3: Calculate new remainder for next iteration.
            // This is what's "left over" after the division step.
            remainder = remainder % den;
            // If remainder becomes 0, division terminates (no more decimal digits).
            // If remainder repeats a previous value, we found the cycle!
        }
        
        return res;
    }
};
