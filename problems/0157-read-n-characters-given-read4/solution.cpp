/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        /**
         * Problem: 0157 - Read N Characters Given Read4
         * 
         * Read n characters from file using read4 API that reads 4 chars at a time.
         * 
         * Approach:
         * Call read4 repeatedly, copying characters to buf until:
         * 1. We've read n characters, or
         * 2. read4 returns less than 4 (EOF reached)
         * 
         * Time complexity: O(n).
         * Space complexity: O(1) - only using buf4 temporary buffer.
         */
        
        // Track total characters read so far.
        int total_read = 0;
        char buf4[4];
        
        while (total_read < n) {
            // Read up to 4 characters from file.
            int chars_read = read4(buf4);
            
            // If no more characters in file, stop.
            if (chars_read == 0) {
                break;
            }
            
            // Copy characters from buf4 to buf.
            // Be careful not to exceed n characters.
            int chars_to_copy = min(chars_read, n - total_read);
            for (int i = 0; i < chars_to_copy; i++) {
                buf[total_read + i] = buf4[i];
            }
            
            // Update total count with characters just copied.
            total_read += chars_to_copy;
        }
        
        return total_read;
    }
};
