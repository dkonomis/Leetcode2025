class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        """
        Problem: 0247 - Strobogrammatic Number II
        
        Generate all strobogrammatic numbers of length n.
        Build iteratively from center outward, adding valid pairs.
        Start with base cases and expand by 2 digits each iteration.
        
        Time complexity: O(5^(n/2)) for the number of valid combinations.
        Space complexity: O(5^(n/2)) for storing results.
        """
        reversible_pairs = [
            ['0', '0'], ['1', '1'], 
            ['6', '9'], ['8', '8'], ['9', '6']
        ]
        
        # When n is even (n % 2 == 0), we start with strings of length 0.
        # When n is odd (n % 2 == 1), we start with strings of length 1.
        curr_len = n % 2
        
        # Initialize with base cases.
        queue = ["0", "1", "8"] if curr_len == 1 else [""]
        
        # Build up to length n by adding pairs.
        while curr_len < n:
            curr_len += 2
            next_level = []
            
            # Add pairs around each existing number.
            for num in queue:
                for pair in reversible_pairs:
                    # Avoid leading zeros when building final length.
                    if curr_len != n or pair[0] != '0':
                        next_level.append(pair[0] + num + pair[1])
            
            queue = next_level
        
        return queue
