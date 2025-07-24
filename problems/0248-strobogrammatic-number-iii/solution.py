class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        """
        Problem: 0248 - Strobogrammatic Number III
        
        Count strobogrammatic numbers in range [low, high].
        Generate all strobogrammatic numbers for each length in range.
        Check if each generated number falls within the bounds.
        
        Time complexity: O(5^(n/2) * n) where n is the max length.
        Space complexity: O(5^(n/2)) for storing generated numbers.
        """
        count = 0
        
        # Process each possible length.
        for length in range(len(low), len(high) + 1):
            # Generate all strobogrammatic numbers of current length.
            nums = self.findStrobogrammatic(length)
            
            for num in nums:
                # Skip numbers with leading zeros (except "0" itself).
                if len(num) > 1 and num[0] == '0':
                    continue
                
                # Check if number is in range [low, high].
                if length == len(low) and num < low:
                    continue
                if length == len(high) and num > high:
                    continue
                
                count += 1
        
        return count
    
    def findStrobogrammatic(self, n: int) -> List[str]:
        """Generate all strobogrammatic numbers of length n."""
        reversible_pairs = [
            ['0', '0'], ['1', '1'], 
            ['6', '9'], ['8', '8'], ['9', '6']
        ]
        
        # Start with base cases.
        curr_len = n % 2
        queue = ["0", "1", "8"] if curr_len == 1 else [""]
        
        # Build up to length n.
        while curr_len < n:
            curr_len += 2
            next_level = []
            
            for num in queue:
                for pair in reversible_pairs:
                    next_level.append(pair[0] + num + pair[1])
            
            queue = next_level
        
        return queue
