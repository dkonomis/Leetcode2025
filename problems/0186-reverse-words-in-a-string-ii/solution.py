class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Problem: 0186 - Reverse Words in a String II
        
        Reverse the order of words in a character array in-place.
        Each word is a sequence of non-space characters separated by single spaces.
        
        Approach:
        - First reverse the entire array to get words in reverse order
        - Then reverse each individual word to restore correct character order
        - Use two pointers to identify word boundaries
        
        Time complexity: O(n) where n is the length of the array.
        Space complexity: O(1) as we modify in-place.
        """
        def reverse(left, right):
            # Helper function to reverse a portion of the array.
            while left < right:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1
        
        n = len(s)
        
        # Step 1: Reverse the entire array.
        reverse(0, n - 1)
        
        # Step 2: Reverse each individual word.
        start = 0
        for i in range(n):
            # When we hit a space or reach the end, reverse the current word.
            if s[i] == ' ':
                reverse(start, i - 1)
                start = i + 1
            elif i == n - 1:
                # Don't forget to reverse the last word.
                reverse(start, i)
        
        # The array is modified in-place, so no return value.
