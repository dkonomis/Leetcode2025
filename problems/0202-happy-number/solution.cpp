class Solution {
public:
    bool isHappy(int n) {
        /*
         * Problem: 0202 - Happy Number
         * Determine if a number is happy by repeatedly replacing it with the sum
         * of squares of its digits until it reaches 1 or enters a cycle.
         * 
         * Approach: Use a set to track seen numbers. If we encounter a number
         * we've seen before, we're in a cycle. If we reach 1, it's happy.
         * 
         * Time complexity: O(log n) on average for happy numbers.
         * Space complexity: O(log n) for the set storing seen numbers.
         */
        
        unordered_set<int> seen;
        
        // Continue until we reach 1 or detect a cycle.
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);  // Mark current number as seen.
            n = getSumOfSquares(n);  // Replace with sum of squares.
        }
        
        // If we exited because n == 1, it's happy. Otherwise, we found a cycle.
        return n == 1;
    }
    
private:
    int getSumOfSquares(int num) {
        // Calculate sum of squares of digits.
        int total = 0;
        while (num > 0) {
            int digit = num % 10;  // Get last digit.
            total += digit * digit;  // Add square of digit.
            num /= 10;  // Remove last digit.
        }
        return total;
    }
};
