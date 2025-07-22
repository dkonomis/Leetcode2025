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
    def __init__(self):
        # Instance variables to maintain state between read calls.
        self.buf4 = [''] * 4      # Buffer for read4.
        self.buf4_count = 0       # Number of valid chars in buf4.
        self.buf4_index = 0       # Current index in buf4.
    
    def read(self, buf, n):
        """
        Problem: 0158 - Read N Characters Given Read4 II - Call Multiple Times
        
        Read n characters from file using read4 API. Handle multiple calls.
        
        Approach:
        Maintain state between calls using instance variables:
        - buf4: stores characters from last read4 call
        - buf4_count: how many valid chars in buf4
        - buf4_index: next char to read from buf4
        
        First consume leftover chars from previous call, then read new chars.
        
        Time complexity: O(n).
        Space complexity: O(1) - only using fixed buf4 buffer.
        
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        total_read = 0
        
        while total_read < n:
            # If we've consumed all chars from buf4, read more.
            if self.buf4_index >= self.buf4_count:
                self.buf4_count = read4(self.buf4)
                self.buf4_index = 0
                
                # If no more chars in file, stop.
                if self.buf4_count == 0:
                    break
            
            # Copy chars from buf4 to buf.
            while total_read < n and self.buf4_index < self.buf4_count:
                buf[total_read] = self.buf4[self.buf4_index]
                total_read += 1
                self.buf4_index += 1
        
        return total_read"""
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
    def __init__(self):
        # Instance variables to maintain state between read calls.
        self.buf4 = [''] * 4      # Buffer for read4.
        self.buf4_count = 0       # Number of valid chars in buf4.
        self.buf4_index = 0       # Current index in buf4.
    
    def read(self, buf, n):
        """
        Problem: 0158 - Read N Characters Given Read4 II - Call Multiple Times
        
        Read n characters from file using read4 API. Handle multiple calls.
        
        Approach:
        Maintain state between calls using instance variables:
        - buf4: stores characters from last read4 call
        - buf4_count: how many valid chars in buf4
        - buf4_index: next char to read from buf4
        
        First consume leftover chars from previous call, then read new chars.
        
        Time complexity: O(n).
        Space complexity: O(1) - only using fixed buf4 buffer.
        
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        total_read = 0
        
        while total_read < n:
            # If we've consumed all chars from buf4, read more.
            if self.buf4_index >= self.buf4_count:
                self.buf4_count = read4(self.buf4)
                self.buf4_index = 0
                
                # If no more chars in file, stop.
                if self.buf4_count == 0:
                    break
            
            # Copy chars from buf4 to buf.
            while total_read < n and self.buf4_index < self.buf4_count:
                buf[total_read] = self.buf4[self.buf4_index]
                total_read += 1
                self.buf4_index += 1
        
        return total_read
