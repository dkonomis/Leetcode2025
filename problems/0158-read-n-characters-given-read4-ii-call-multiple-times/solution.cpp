/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    // Instance variables to maintain state between read calls.
    char buf4[4];      // Buffer for read4.
    int buf4_count = 0;  // Number of valid chars in buf4.
    int buf4_index = 0;  // Current index in buf4.
    
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        /**
         * Problem: 0158 - Read N Characters Given Read4 II - Call Multiple Times
         * 
         * Read n characters from file using read4 API. Handle multiple calls.
         * 
         * Approach:
         * Maintain state between calls using instance variables:
         * - buf4: stores characters from last read4 call
         * - buf4_count: how many valid chars in buf4
         * - buf4_index: next char to read from buf4
         * 
         * First consume leftover chars from previous call, then read new chars.
         * 
         * Time complexity: O(n).
         * Space complexity: O(1) - only using fixed buf4 buffer.
         */
        
        int total_read = 0;
        
        while (total_read < n) {
            // If we've consumed all chars from buf4, read more.
            if (buf4_index >= buf4_count) {
                buf4_count = read4(buf4);
                buf4_index = 0;
                
                // If no more chars in file, stop.
                if (buf4_count == 0) {
                    break;
                }
            }
            
            // Copy chars from buf4 to buf.
            while (total_read < n && buf4_index < buf4_count) {
                buf[total_read] = buf4[buf4_index];
                total_read++;
                buf4_index++;
            }
        }
        
        return total_read;
    }
};
