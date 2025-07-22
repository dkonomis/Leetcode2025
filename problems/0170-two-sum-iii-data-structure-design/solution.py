class TwoSum:
    """
    0170 - Two Sum III - Data Structure Design
    
    Design data structure to support add numbers and find if any pair sums to target.
    Optimize for fast add operations with acceptable find performance.
    
    Approach:
    - Use HashMap to store number frequencies for O(1) add operations
    - For find, iterate through all stored numbers and check for valid complement
    - Handle two cases: different numbers (need complement to exist) and 
      same number (need frequency > 1 for cases like 3+3=6)
    
    Time complexity: add O(1), find O(n).
    Space complexity: O(n).
    """

    def __init__(self):
        """Initialize the data structure with empty frequency map."""
        self.num_freq = {}

    def add(self, number: int) -> None:
        """
        Add number to internal data structure.
        
        Args:
            number: Integer to add to the data structure
        """
        # Increment frequency count for this number.
        if number in self.num_freq:
            self.num_freq[number] += 1
        else:
            self.num_freq[number] = 1

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum equals value.
        
        Args:
            value: Target sum to search for
            
        Returns:
            True if pair exists, False otherwise
        """
        # Check each stored number for a valid complement.
        for num in self.num_freq.keys():
            complement = value - num
            
            if complement != num:
                # Different numbers: just need complement to exist.
                if complement in self.num_freq:
                    return True
            elif self.num_freq[num] > 1:
                # Same number case: need at least 2 occurrences (num + num = value).
                return True
        
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
