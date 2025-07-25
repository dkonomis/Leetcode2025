class Solution {
public:
    string numberToWords(int num) {
        /**
         * Problem: 0273 - Integer to English Words
         * 
         * Convert non-negative integer to English words representation.
         * 
         * Approach: Process number in groups of three digits (thousands, millions, billions).
         * For each group, convert to words and append appropriate suffix. Handle special
         * cases like teens and zero.
         * 
         * Time complexity: O(1) since input is bounded by 2^31 - 1.
         * Space complexity: O(1) for the fixed-size word arrays.
         */
        
        if (num == 0) {
            return "Zero";
        }
        
        // Words for thousands.
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        
        string res = "";
        int group_index = 0;
        
        // Process groups of three digits from right to left.
        while (num > 0) {
            if (num % 1000 != 0) {
                // Convert group and add thousand suffix if needed.
                string group_words = helper(num % 1000);
                if (thousands[group_index] != "") {
                    group_words += " " + thousands[group_index];
                }
                // Prepend to result.
                res = group_words + (res != "" ? " " + res : "");
            }
            
            num /= 1000;
            group_index++;
        }
        
        return res;
    }
    
private:
    string helper(int n) {
        /**
         * Convert number less than 1000 to words.
         */
        
        // Words for numbers 1-19.
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", 
                               "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", 
                               "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        
        // Words for tens.
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", 
                               "Seventy", "Eighty", "Ninety"};
        
        if (n == 0) {
            return "";
        } else if (n < 20) {
            return ones[n];
        } else if (n < 100) {
            return tens[n / 10] + (n % 10 != 0 ? " " + ones[n % 10] : "");
        } else {
            // Handle hundreds.
            return ones[n / 100] + " Hundred" + (n % 100 != 0 ? " " + helper(n % 100) : "");
        }
    }
};
