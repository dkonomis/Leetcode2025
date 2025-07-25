class Solution:
    def numberToWords(self, num: int) -> str:
        """
        Problem: 0273 - Integer to English Words
        
        Convert non-negative integer to English words representation.
        
        Approach: Process number in groups of three digits (thousands, millions, billions).
        For each group, convert to words and append appropriate suffix. Handle special
        cases like teens and zero.
        
        Time complexity: O(1) since input is bounded by 2^31 - 1.
        Space complexity: O(1) for the fixed-size word arrays.
        """
        if num == 0:
            return "Zero"
        
        # Words for numbers 1-19.
        ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", 
                "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", 
                "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        
        # Words for tens.
        tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", 
                "Seventy", "Eighty", "Ninety"]
        
        # Words for thousands.
        thousands = ["", "Thousand", "Million", "Billion"]
        
        def helper(n):
            """Convert number less than 1000 to words."""
            if n == 0:
                return ""
            elif n < 20:
                return ones[n]
            elif n < 100:
                return tens[n // 10] + (" " + ones[n % 10] if n % 10 else "")
            else:
                # Handle hundreds.
                return ones[n // 100] + " Hundred" + (" " + helper(n % 100) if n % 100 else "")
        
        res = ""
        group_index = 0
        
        # Process groups of three digits from right to left.
        while num > 0:
            if num % 1000 != 0:
                # Convert group and add thousand suffix if needed.
                group_words = helper(num % 1000)
                if thousands[group_index]:
                    group_words += " " + thousands[group_index]
                # Prepend to result.
                res = group_words + (" " + res if res else "")
            
            num //= 1000
            group_index += 1
        
        return res
