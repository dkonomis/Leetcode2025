class Solution:
    def reverseWords(self, s: str) -> str:
        """
        Problem: 0151 - Reverse Words in a String
        
        Reverse the order of words in a string. Handle multiple spaces
        and leading/trailing spaces.
        
        Approach:
        Use deque (double-ended queue) to build result efficiently.
        Parse words with two pointers and add to front of deque.
        This naturally reverses the order.
        
        Time complexity: O(n).
        Space complexity: O(n) for the deque and result.
        """
        from collections import deque
        
        res = deque()
        left = 0
        
        while left < len(s):
            # Skip spaces.
            while left < len(s) and s[left] == ' ':
                left += 1
            
            if left >= len(s):
                break
            
            # Find end of current word.
            right = left
            while right < len(s) and s[right] != ' ':
                right += 1
            
            # Add word to front of deque - this reverses order.
            word = s[left:right]
            if res:
                # If not first word, add space before it.
                res.appendleft(' ')
            res.appendleft(word)
            
            # Move to next word.
            left = right
        
        # Join deque elements into final string.
        return ''.join(res)
