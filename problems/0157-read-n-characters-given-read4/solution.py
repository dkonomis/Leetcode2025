"""
The read4 API is already defined for you.

    @param buf4, a list of 4 characters
    @return an integer
    def read4(buf4):

# Below is an example of how the read4 API can be called.
file = File("abcdefghijk") # File is "abcdefghijk", initially file pointer (fp) points to 'a'
buf4 = [' '] * 4 # Create buffer with enough space to store characters
read4(buf4) # read4 returns 4. Now buf = ['a','b','c','d'], fp points to 'e'
read4(buf4) # read4 returns 4. Now buf = ['e','f','g','h'], fp points to 'i'
read4(buf4) # read4 returns 3. Now buf = ['i','j','k',...], fp points to end of file
"""

class Solution:
    def read(self, buf, n):
        """
        Problem: 0157 - Read N Characters Given Read4
        
        Read n characters from file using read4 API that reads 4 chars at a time.
        
        Approach:
        Call read4 repeatedly, copying characters to buf until:
        1. We've read n characters, or
        2. read4 returns less than 4 (EOF reached)
        
        Time complexity: O(n).
        Space complexity: O(1) - only using buf4 temporary buffer.
        
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        # Track total characters read so far.
        total_read = 0
        buf4 = [''] * 4
        
        while total_read < n:
            # Read up to 4 characters from file.
            chars_read = read4(buf4)
            
            # If no more characters in file, stop.
            if chars_read == 0:
                break
            
            # Copy characters from buf4 to buf.
            # Be careful not to exceed n characters.
            chars_to_copy = min(chars_read, n - total_read)
            for i in range(chars_to_copy):
                buf[total_read + i] = buf4[i]
            
            # Update total count with characters just copied.
            total_read += chars_to_copy
        
        return total_read
